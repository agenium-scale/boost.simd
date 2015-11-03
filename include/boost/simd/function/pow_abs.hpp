//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POW_ABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POW_ABS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Computes \f$|x|^y\f$.

    @par Semantic:

    For every parameters of floating type  T:

    @code
    T r = pow_abs(x, y);
    @endcode

    is similar to:

    @code
    T r = pow(abs(x), y);
    @endcode

    @see pow, abs


    @return a value of the same type as the parameter

**/
  template<typename T> auto pow_abs(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Computes  \f$|x|^y\f$.


      Function object tied to simd::pow_abs

      @see simd::pow_abs
    **/
    const boost::dispatch::functor<tag::pow_abs_> pow_abs = {};
  }
} }
#endif

#include <boost/simd/function/scalar/pow_abs.hpp>
#include <boost/simd/function/simd/pow_abs.hpp>

#endif
