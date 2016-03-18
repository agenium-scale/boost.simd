//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_INVALID_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_INVALID_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_not_invalid capabilities

    Returns @ref True if x is not inf, -inf or nan, else returns @ref False.

    This is a convenient alias of @ref is_finite
  **/
  const boost::dispatch::functor<tag::is_not_invalid_> is_not_invalid = {};
} }
#endif

#include <boost/simd/function/scalar/is_finite.hpp>
#include <boost/simd/function/simd/is_not_invalid.hpp>

#endif
