//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ANGLE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ANGLE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing angle capabilities

    Computes the angular orientation of its parameter.

    This is a convenient alias of @ref arg
  **/
  const boost::dispatch::functor<tag::angle_> angle = {};
} }
#endif

#include <boost/simd/function/scalar/angle.hpp>
#include <boost/simd/function/simd/angle.hpp>

#endif
