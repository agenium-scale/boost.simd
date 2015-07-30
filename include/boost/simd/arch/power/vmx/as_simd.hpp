//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for VMX like extensions

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_AS_SIMD_HPP_INCLUDED

#include <boost/simd/arch/common/simd/as_simd.hpp>
#include <boost/dispatch/meta/introspection/is_natural.hpp>
#include <boost/dispatch/meta/introspection/sign_of.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd
{
  template<typename T> struct logical;

  namespace ext
  {
    template<> struct as_simd<float, boost::simd::vmx_>
    {
      using type = __vector float;
    };

#if BOOST_HW_SIMD_PPC == BOOST_HW_SIMD_PPC_VSX_VERSION
    template<> struct as_simd<double, boost::simd::vmx_>
    {
      using type = __vector double;
    };
#endif

    template<typename T>
    struct as_simd<logical<T>, boost::simd::vmx_>
    {
      using t2b = brigand::map< brigand::pair<brigand::int_<1>,__vector __bool char  >
                              , brigand::pair<brigand::int_<2>,__vector __bool short >
                              , brigand::pair<brigand::int_<4>,__vector __bool int   >
#if BOOST_HW_SIMD_PPC == BOOST_HW_SIMD_PPC_VSX_VERSION
                              , brigand::pair<brigand::int_<8>,__vector __bool long  >
#endif
                              >;

      using type = brigand::at<t2b, brigand::int_<sizeof(T)>>;
    };

    template<typename T>
    struct as_simd< T, boost::simd::vmx_
                  , typename std::enable_if<boost::dispatch::is_natural<T>::value>
                  >
    {
      using t2b = brigand::map< brigand::pair < brigand::list<brigand::int_<1>,signed>
                                              , __vector signed char
                                              >
                              , brigand::pair < brigand::list<brigand::int_<1>,unsigned>
                                              , __vector unsigned char
                                              >
                              , brigand::pair < brigand::list<brigand::int_<2>,signed>
                                              , __vector signed short
                                              >
                              , brigand::pair < brigand::list<brigand::int_<2>,unsigned>
                                              , __vector unsigned short
                                              >
                              , brigand::pair < brigand::list<brigand::int_<4>,signed>
                                              , __vector signed int
                                              >
                              , brigand::pair < brigand::list<brigand::int_<4>,unsigned>
                                              , __vector unsigned int
                                              >
#if BOOST_HW_SIMD_PPC == BOOST_HW_SIMD_PPC_VSX_VERSION
                              , brigand::pair < brigand::list<brigand::int_<8>,signed>
                                              , __vector signed long
                                              >
                              , brigand::pair < brigand::list<brigand::int_<8>,unsigned>
                                              , __vector unsigned long
                                              >
#endif
                              >;

      using type = brigand::at< t2b
                              , brigand::list<brigand::int_<sizeof(T)>,boost::dispacth::sign_of<T>>
                              >;
    };
  }
} }

#endif
