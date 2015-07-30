//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for VMX like extensions

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_DETAIL_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_DETAIL_AS_SIMD_HPP_INCLUDED

#include <boost/simd/arch/common/simd/detail/as_simd.hpp>
#include <boost/dispatch/meta/introspection/is_natural.hpp>
#include <boost/dispatch/meta/introspection/sign_of.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd
{
  template<typename T> struct logical;

  namespace detail
  {
    template<> struct as_simd<float, boost::simd::vmx_>
    {
      using type = __vector float;
    };

    template<typename T>
    struct as_simd<logical<T>, boost::simd::vmx_>
    {
      using t2b = brigand::map< brigand::pair<brigand::int_<1>,__vector __bool char  >
                              , brigand::pair<brigand::int_<2>,__vector __bool short >
                              , brigand::pair<brigand::int_<4>,__vector __bool int   >
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
                              , brigand::pair < brigand::list<brigand::int_<2>,signed>
                                              , __vector signed short
                                              >
                              , brigand::pair < brigand::list<brigand::int_<4>,signed>
                                              , __vector signed int
                                              >
                              , brigand::pair < brigand::list<brigand::int_<1>,unsigned>
                                              , __vector unsigned char
                                              >
                              , brigand::pair < brigand::list<brigand::int_<2>,unsigned>
                                              , __vector unsigned short
                                              >
                              , brigand::pair < brigand::list<brigand::int_<4>,unsigned>
                                              , __vector unsigned int
                                              >
                              >;

      using type = brigand::at< t2b
                              , brigand::list<brigand::int_<sizeof(T)>,boost::dispacth::sign_of<T>>
                              >;
    };
  }
} }

#endif
