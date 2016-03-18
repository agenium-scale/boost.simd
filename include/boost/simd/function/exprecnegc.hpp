//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing exprecnegc capabilities

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

  **/
  const boost::dispatch::functor<tag::exprecnegc_> exprecnegc = {};
} }
#endif

#include <boost/simd/function/scalar/exprecnegc.hpp>
#include <boost/simd/function/simd/exprecnegc.hpp>

#endif
