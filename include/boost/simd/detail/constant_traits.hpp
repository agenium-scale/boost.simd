//==================================================================================================
/*!
  @file

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TRAITS_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/scalar_of.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy.hpp>

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
} } }

#endif
