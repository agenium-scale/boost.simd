//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEXTPOW2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEXTPOW2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the greatest integer n such that abss(x) is greater or equal to \f$2^n\f$

    @par Semantic:

    @code
    T n = nextpow2(x);
    @endcode

    is similar to:

    @code
    T n = floor(log2(abss(x)));
    @endcode


    @return an integral value of same type as the input

**/
  template<typename T> auto nextpow2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the greatest integer n such that abs(x) is greater or equal to \f$2^n\f$


      Function object tied to simd::nextpow2

      @see simd::nextpow2
    **/
    const boost::dispatch::functor<tag::nextpow2_> nextpow2 = {};
  }
} }
#endif

#include <boost/simd/function/definition/nextpow2.hpp>
#include <boost/simd/arch/common/scalar/function/nextpow2.hpp>
#include <boost/simd/function/simd/nextpow2.hpp>

#endif
