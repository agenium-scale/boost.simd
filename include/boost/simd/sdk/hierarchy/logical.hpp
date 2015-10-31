//==================================================================================================
/*!
  @file

  Defines the logical_ hierarchy

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_HIERARCHY_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_SDK_HIERARCHY_LOGICAL_HPP_INCLUDED

#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/hierarchy/fundamental.hpp>
#include <boost/dispatch/property_of.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-sdk
    @brief Logical type hierarchy tag

    Types classified as logical_ have properties similar to logical<T>

    @tparam T Base hierarchy
  **/
  template<typename T> struct logical_ : boost::dispatch::fundamental_<T>
  {
    using parent = boost::dispatch::fundamental_<T>;
  };
} }

namespace boost { namespace dispatch
{
  namespace ext
  {
    template<typename T> struct model_of<boost::simd::logical<T>>
    {
      template<typename X> struct apply { using type = boost::simd::logical<X>; };
    };

    template<typename T> struct value_of<boost::simd::logical<T>>
    {
      using type = T;
    };

    template<typename T, typename Origin>
    struct property_of<boost::simd::logical<T>,Origin>
    {
      using type = boost::simd::logical_<Origin>;
    };

    template<class T>
    struct scalar_of< simd::logical<T> >
    {
      typedef boost::simd::logical<T> type;
    };
  }
} }

#endif
