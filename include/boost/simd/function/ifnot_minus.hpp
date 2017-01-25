//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_MINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_MINUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    This function object conditionally returns  @c x (respectively @c x-y)
    if @c c is @ref True (respectively  @ref False)

   @par Example:

     @snippet ifnot_minus.cpp ifnot_minus

   @par Possible output:

     @snippet ifnot_minus.txt ifnot_minus

  **/
  Value ifnot_minus(Value const& c, Value const& x, Value const& y);

  /*!
    @overload
  */
  Value ifnot_minus(LogicalValue const& c, Value const& x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/ifnot_minus.hpp>
#include <boost/simd/function/simd/ifnot_minus.hpp>

#endif
