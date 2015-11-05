//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POW2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POW2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Returns \f$ x 2^y\f$.  (the result is undefined on overflow and
    the function asserts for invalid second parameter )

    @par Semantic:

    For every parameters of floating type T

    @code
    T r = pow2(x, y);
    @endcode

    is similar to:

    @code
    T r = x*exp2(trunc(y));
    @endcode

    @see exp2, trunc, ldexp

    @return a value of the same type as the parameter

**/
  template<typename T> auto pow2(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Returns \f$ x 2^y\f$.


      Function object tied to simd::pow2

      @see simd::pow2
    **/
    const boost::dispatch::functor<tag::pow2_> pow2 = {};
  }
} }
#endif

#include <boost/simd/function/scalar/pow2.hpp>
#include <boost/simd/function/simd/pow2.hpp>

#endif
