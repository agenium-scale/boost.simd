//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-operator
    This function object returns the first entry *logically* shifted right
    by value of the second entry which must be of integer type and of the same number
    of elements as the first parameter or scalar.

    If the second entry is negative
    the result is not defined.

    @see  shift_right, shift_left, rshl, rshr, rol, ror



    @par Header <boost/simd/function/shr.hpp>

   @par Example:

     @snippet shr.cpp shr

   @par Possible output:

     @snippet shr.txt shr

  **/
  Value shr(Value const & x, IntegerValue const& n);
} }
#endif

#include <boost/simd/function/scalar/shr.hpp>
#include <boost/simd/function/simd/shr.hpp>

#endif
