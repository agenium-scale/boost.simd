//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPRECNEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPRECNEG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Computes the  function: \f$e^{-\frac1x}\f$

    @par Semantic:

    For every parameter of floating type T0

    @code
    T r = exprecneg(x);
    @endcode

    is equivalent to
    @code
    T r = exp(-rec((x)));
    @endcode


    @see exp, exprecnegc

    @return a value of the same type as the (floating) input parameter

**/
  template<typename T> auto exprecneg(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Computes the  function: \f$e^{-\frac1x}\f$


      Function object tied to simd::exprecneg

      @see simd::exprecneg
    **/
    const boost::dispatch::functor<tag::exprecneg_> exprecneg = {};
  }
} }
#endif

#include <boost/simd/function/scalar/exprecneg.hpp>
#include <boost/simd/function/simd/exprecneg.hpp>

#endif
