//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGNIFICANTS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGNIFICANTS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Compute the rounding to n significants digits

    @par Semantic:

    For every parameter of floating type T and strictly positive integer n

    @code
    T r = significants(x, n);
    @endcode

    is equivalent to round(x, m) where m is n-iceil(log10(abs(x)))

    @see round,  iceil, log10

    @return a value of the same type as the parameter

**/
  template<typename T, typename N> auto significants(T const& x, N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Compute the rounding to n significants digits


      Function object tied to simd::significants

      @see simd::significants
    **/
    const boost::dispatch::functor<tag::significants_> significants = {};
  }
} }
#endif

#include <boost/simd/function/scalar/significants.hpp>
#include <boost/simd/function/simd/significants.hpp>

#endif
