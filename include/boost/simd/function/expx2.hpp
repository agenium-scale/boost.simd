//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPX2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPX2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    exponential of square function: \f$e^{x^2}\f$ or \f$e^{-x^2}\f$

    @par Semantic:

    For every parameters of floating type T

    @code
    T r = expx2(x, s);
    @endcode

    is similar to:

    @code
    T r =  exp(signnz(s)*x*x);
    @endcode

    @par Note:
    provisions are made for obtaining more accurate results for large x.
    s default to 1.

    @see exp

    @return a value of the same type as the parameter

**/
  template<typename T> auto expx2(T const& x, T const& s) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      exponential of square function: \f$e^{x^2}\f$ or \f$e^{-x^2}\f$


      Function object tied to simd::expx2

      @see simd::expx2
    **/
    const boost::dispatch::functor<tag::expx2_> expx2 = {};
  }
} }
#endif

#include <boost/simd/function/scalar/expx2.hpp>
#include <boost/simd/function/simd/expx2.hpp>

#endif
