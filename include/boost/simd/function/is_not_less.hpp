//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_LESS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_LESS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-predicates

    TODO Put description here

   @par Note

     Call to `is_not_less(x,y)` is similar to: `!(x < y)`

   @par Example:

     @snippet is_not_less.cpp is_not_less

   @par Possible output:

     @snippet is_not_less.txt is_not_less

  **/
  as_logical_t<Value> is_not_less(Value const& x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/is_not_less.hpp>
#include <boost/simd/function/simd/is_not_less.hpp>

#endif
