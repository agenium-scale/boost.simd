//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TRAITS_HPP_INCLUDED

#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <boost/config.hpp>

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4310) // Truncation
#pragma warning(disable: 4309) // Truncation
#endif

/*!

**/
#define BOOST_SIMD_REGISTER_CONSTANT(INT,FLOAT,DOUBLE)                                              \
struct value_map                                                                                    \
{                                                                                                   \
  template<typename X>                                                                              \
  static std::integral_constant<X,X(INT)> value(boost::dispatch::integer_<X> const&);               \
  template<typename X>                                                                              \
  static brigand::single_<FLOAT> value(boost::dispatch::single_<X> const&);                         \
  template<typename X>                                                                              \
  static brigand::double_<DOUBLE> value(boost::dispatch::double_<X> const&);                        \
}                                                                                                   \
/**/

namespace boost { namespace simd { namespace detail
{
  template<typename Tag, typename T>
  struct constant_traits
  {
    using key  = boost::dispatch::property_of_t<boost::dispatch::scalar_of_t<T>>;
    using base = typename Tag::value_map;
    using type = decltype( base::value(key()) );
  };

  template<typename RealType, std::intmax_t N, std::intmax_t D = 1>
  struct ratio {};

  template<typename T, std::intmax_t N>
  struct  constantify
  {
    using type = std::integral_constant<T,T(N)>;
  };

  template<std::intmax_t V> struct constantify<double,V>
  {
    using type = brigand::double_<V>;
  };

  template<std::intmax_t V> struct constantify<float,V>
  {
    using type = brigand::single_<V>;
  };
} } }

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#endif
