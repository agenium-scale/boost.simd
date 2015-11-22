//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_OPTIONS_OF_HPP_INCLUDED
#define BOOST_SIMD_OPTIONS_OF_HPP_INCLUDED

//#include <boost/dispatch/hierarchy/base.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-api

    Various options that can be used as additional type parameter
    to modify the accuracy, speed, etc. of some boost simd functions or function objects

  **/

  struct fast_tag
  {
    using parent = fast_tag;
    using hierarchy_tag = void; //dispatch::detail::hierarchy_tag;
  };

  const fast_tag fast_ = {};

  struct raw_tag
  {
    using parent = raw_tag;
    using hierarchy_tag = void; //dispatch::detail::hierarchy_tag;
  };

  const raw_tag raw_ = {};

  /// selection tags for throwing and asserting

  struct assert_tag
  {
    using parent = assert_tag;
    using hierarchy_tag = void; //dispatch::detail::hierarchy_tag;
  };

  const assert_tag assert_ = {};

  struct throw_tag
  {
    using parent = throw_tag;
    using hierarchy_tag = void; //dispatch::detail::hierarchy_tag;
  };

  const throw_tag throw_ = {};
} }

#endif
