//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GAMMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GAMMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-euler
    Function object implementing gamma capabilities

   Computes the gamma function:
   \f$\displaystyle \int_0^{\infty} t^{x-1}e^{-t}\mbox{d}t\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = gamma(x);
    @endcode

    @see gammaln

  **/
  Value gamma(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/gamma.hpp>
//#include <boost/simd/function/simd/gamma.hpp>

#endif
