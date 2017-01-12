//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_POSITIVE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_POSITIVE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-predicates

    This function object returns @ref True if x is positive else @ref False.

    This function differs from @ref is_gtz for floating point arguments,
    because @ref Zero is positive but not greater than 0, and @ref Mzero is
    not positive and not greater than 0, It's probably @ref is_gtz that
    you want.

   @par Note

     Call to `is_positive(x)` is similar to: `if x is of signed type` auto r = bitofsign(x) == 0;  else  auto r = True ;

   @par Example:

     @snippet is_positive.cpp is_positive

   @par Possible output:

     @snippet is_positive.txt is_positive

  **/
  as_logical_t<Value> is_positive(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/is_positive.hpp>
#include <boost/simd/function/simd/is_positive.hpp>

#endif
