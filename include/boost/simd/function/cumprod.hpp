//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CUMPROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CUMPROD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost {
namespace simd {

/*!
   @ingroup group-reduction
   This function object computes the cumulated product of the argument elements.

   Take care that overflow is very easy to get here especially for integral
 types.

  @see cumsum


    @par Header <boost/simd/function/cumprod.hpp>

  @par Example:

    @snippet cumprod.cpp cumprod

  @par Possible output:

    @snippet cumprod.txt cumprod

 **/
Value cumprod(Value const &x);
}
}
#endif

#include <boost/simd/function/scalar/cumprod.hpp>
#include <boost/simd/function/simd/cumprod.hpp>

#endif
