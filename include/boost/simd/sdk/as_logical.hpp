//==================================================================================================
/*!
  @file

  Defines the as_logical meta-function

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_AS_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_SDK_AS_LOGICAL_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/sdk/real_of.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/dispatch/meta/factory_of.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd
{
  template<typename T> struct logical;

  /*!
    @ingroup  group-api
    @brief    COnvert types to a logical type

    For a given type @c T , provides a type of same structure but able to fit a logical value.
    Provisions are taken so that conversion of logical and bool types is idempotent.

    @tparam T      Type to convert
  **/
  template<typename T>
  struct  as_logical
  {
    using type = brigand::apply < dispatch::factory_of<T, dispatch::scalar_of_t<T>>
                                , logical<real_of_t<T>>
                                >;
  };

  template<typename T> struct as_logical< logical<T> >
  {
    using type = logical<T>;
  };

  template<> struct as_logical< bool >
  {
    using type = bool;
  };

  /*!
    @ingroup  group-api
    @brief Eager short-cut to as_logical meta-function
  **/
  template<typename T> using as_logical_t = typename as_logical<T>::type;
} }

#endif
