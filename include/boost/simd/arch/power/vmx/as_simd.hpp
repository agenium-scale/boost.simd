//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for VMX like extensions

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_AS_SIMD_HPP_INCLUDED

#include <boost/simd/arch/power/tags.hpp>
#include <boost/simd/arch/common/simd/as_simd.hpp>
#include <boost/dispatch/meta/is_natural.hpp>
#include <boost/dispatch/meta/sign_of.hpp>
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
      using t2b = brigand::map< brigand::pair<brigand::int32_t<1>,__vector __bool char  >
                              , brigand::pair<brigand::int32_t<2>,__vector __bool short >
                              , brigand::pair<brigand::int32_t<4>,__vector __bool int   >
#if BOOST_HW_SIMD_PPC == BOOST_HW_SIMD_PPC_VSX_VERSION
                              , brigand::pair<brigand::int32_t<8>,__vector __bool long  >
#endif
                              >;

      using type = brigand::at<t2b, brigand::int32_t<sizeof(T)>>;
    };

    template<typename T>
    struct as_simd< T, boost::simd::vmx_
                  , typename std::enable_if<boost::dispatch::is_natural<T>::value>
                  >
    {
      using t2b = brigand::map< brigand::pair < brigand::list<brigand::int32_t<1>,signed>
                                              , __vector signed char
                                              >
                              , brigand::pair < brigand::list<brigand::int32_t<1>,unsigned>
                                              , __vector unsigned char
                                              >
                              , brigand::pair < brigand::list<brigand::int32_t<2>,signed>
                                              , __vector signed short
                                              >
                              , brigand::pair < brigand::list<brigand::int32_t<2>,unsigned>
                                              , __vector unsigned short
                                              >
                              , brigand::pair < brigand::list<brigand::int32_t<4>,signed>
                                              , __vector signed int
                                              >
                              , brigand::pair < brigand::list<brigand::int32_t<4>,unsigned>
                                              , __vector unsigned int
                                              >
#if BOOST_HW_SIMD_PPC == BOOST_HW_SIMD_PPC_VSX_VERSION
                              , brigand::pair < brigand::list<brigand::int32_t<8>,signed>
                                              , __vector signed long
                                              >
                              , brigand::pair < brigand::list<brigand::int32_t<8>,unsigned>
                                              , __vector unsigned long
                                              >
#endif
                              >;

      using type = brigand::at< t2b
                              , brigand::list<brigand::int32_t<sizeof(T)>,boost::dispatch::sign_of<T>>
                              >;
    };
  }
} }

#endif
