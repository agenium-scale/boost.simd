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

#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <boost/dispatch/as.hpp>
#include <boost/config.hpp>
#include <type_traits>

/*!

**/
#define BOOST_SIMD_REGISTER_CONSTANT(INT,FLOAT,DOUBLE)                                              \
template<typename T>                                                                                \
using value_map = brigand::map                                                                      \
                  < brigand::pair<brigand::no_such_type_      , brigand::uint_<INT>     >           \
                  , brigand::pair<boost::dispatch::single_<T> , brigand::single_<FLOAT> >           \
                  , brigand::pair<boost::dispatch::double_<T> , brigand::double_<DOUBLE>>           \
                  >                                                                                 \
/**/

namespace boost { namespace simd { namespace detail
{
  template<typename Tag, typename T>
  struct constant_traits
  {
    using cmap = typename Tag::template value_map<T>;
    using key  = boost::dispatch::property_of_t<T>;
    using base = brigand::at<cmap, key >;
    using type = typename std::conditional< std::is_same<base,brigand::no_such_type_>::value
                                          , brigand::at<cmap, brigand::no_such_type_>
                                          , base
                                          >::type;
  };
} } }

#endif
