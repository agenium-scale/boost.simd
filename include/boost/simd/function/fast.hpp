//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FAST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_HPP_INCLUDED

#include <boost/simd/detail/decorator.hpp>

namespace boost { namespace simd
{
  struct fast_tag
  {
    using parent = fast_tag;
    using hierarchy_tag = void;
  };

  const detail::decorator<fast_tag> fast_ = {};
} }

#endif
