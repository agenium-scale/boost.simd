//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-trigonometric
    This function object returns the inverse cosecant in radian: \f$\arcsin(1/x)\f$.

   @see acscd, acscpi, asin, asin, sin, rec



    @par Header <boost/simd/function/acsc.hpp>

   @par Example:

     @snippet acsc.cpp acsc

   @par Possible output:

     @snippet acsc.txt acsc

  **/
  Value acsc(Value const & x);
} }
#endif

#include <boost/simd/function/scalar/acsc.hpp>
#include <boost/simd/function/simd/acsc.hpp>

#endif
