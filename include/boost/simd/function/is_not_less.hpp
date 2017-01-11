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

    @par Semantic:

    @code
    auto r = is_not_less(x,y);
    @endcode

    is similar to:

    @code
    auto r = !(x < y);
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to a call to @ref is_greater_equal
    for floating types

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
