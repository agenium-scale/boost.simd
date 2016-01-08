//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    With a third parameter std_  maxnum(x, y, std_) calls the stdlibc++ function std::fmax.

    @see max, maxnummag,  maxmag

    @return a value of same type as the inputs

**/
  template<typename T> auto maxnum(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the maximum value, ignoring nans.


      Function object tied to simd::maxnum

      @see simd::maxnum
    **/
    const boost::dispatch::functor<tag::maxnum_> maxnum = {};
  }
} }
#endif

#include <boost/simd/function/definition/maxnum.hpp>
#include <boost/simd/arch/common/scalar/function/maxnum.hpp>
#include <boost/simd/function/simd/maxnum.hpp>

#endif
