//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COTH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COTH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-hyperbolic

    This unction object returns the hyperbolic cotangent:
    \f$(e^{x}+e^{-x})/(e^{x}-e^{-x})\f$


    @see sinh, cosh, sinhcosh
  **/
  IEEEValue coth(IEEEValue const& x);

  /*
    FIXME: MISSING FILES

    @par Example:

      @snippet coth.cpp coth

    @par Possible output:

      @snippet coth.txt coth
  */
} }
#endif

#include <boost/simd/function/scalar/coth.hpp>
#include <boost/simd/function/simd/coth.hpp>

#endif
