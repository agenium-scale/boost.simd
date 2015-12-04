//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPRECNEGC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPRECNEGC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Computes the  function: \f$1-e^{-\frac1x}\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = exprecnegc(x);
    @endcode

    is equivalent to
    @code
    T r = oneminus(exp(-rec((x))));
    @endcode


    @see exp, exprecneg

    @return a value of the same type as the (floating) input parameter

**/
  template<typename T> auto exprecnegc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Computes the  function: \f$1-e^{-\frac1x}\f$


      Function object tied to simd::exprecnegc

      @see simd::exprecnegc
    **/
    const boost::dispatch::functor<tag::exprecnegc_> exprecnegc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/exprecnegc.hpp>
#include <boost/simd/function/simd/exprecnegc.hpp>

#endif
