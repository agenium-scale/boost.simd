//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RESTRICTED_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RESTRICTED_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/decorator.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  struct restricted_tag : boost::dispatch::unspecified_<restricted_tag>
  {
    using parent = boost::dispatch::unspecified_<restricted_tag>;
  };

  const detail::decorator<restricted_tag> restricted_ = {};
} }

#endif
