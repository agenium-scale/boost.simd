//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAXNUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAXNUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing maxnum capabilities

    Returns the maximum value, ignoring nans.

    @par Semantic:

    @code
    T r = maxnum(x,y);
    @endcode

    is similar to:

    @code
    T r = (is_nan(x) ? y : (isnan(y) ? x : max(x, y));
    @endcode

    @par Alias:
    @c fmax

    With the std_ decorator std_(maxnum)(x, y) calls the stdlibc++ function std::fmax.

    @par Decorators

    std_ for floating entries

    @see max, maxnummag,  maxmag

  **/
  const boost::dispatch::functor<tag::maxnum_> maxnum = {};
} }
#endif

#include <boost/simd/function/scalar/maxnum.hpp>
#include <boost/simd/function/simd/maxnum.hpp>

#endif
