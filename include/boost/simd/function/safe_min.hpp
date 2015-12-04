//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SAFE_MIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SAFE_MIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns a safe mininimal value relative to the input, i.e. a
    value which will not underflow when divided by the input.

    @par Semantic:

    @code
    T r = safe_min(x);
    @endcode

    is similar to:

    @code
    T r =  x ? Sqrtsmallestposval<T>()*abs(x);
    @endcode


    @see Sqrtsmallestposval

    @return a value of same type as the input

**/
  template<typename T> auto safe_min(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns a safe mininimal value relative to the input, i.e. a
      value which will not underflow when divided by the input.


      Function object tied to simd::safe_min

      @see simd::safe_min
    **/
    const boost::dispatch::functor<tag::safe_min_> safe_min = {};
  }
} }
#endif

#include <boost/simd/function/definition/safe_min.hpp>
#include <boost/simd/arch/common/generic/function/safe_min.hpp>
#include <boost/simd/function/simd/safe_min.hpp>

#endif
