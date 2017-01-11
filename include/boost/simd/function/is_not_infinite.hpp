//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_INFINITE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_INFINITE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates

    This function object returns @ref True if x is finite or @ref Nan

    @par Semantic:

    @code
    auto r = is_not_infinite(x);
    @endcode

    is similar to:

    @code
    if x is of floating type
      auto r = (x !=  Inf) && (x != -Inf);
    else
      auto r = True ;
    @endcode


   @par Example:

     @snippet is_not_infinite.cpp is_not_infinite

   @par Possible output:

     @snippet is_not_infinite.txt is_not_infinite

  **/
  as_logical_t<Value> is_not_infinite(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/is_not_infinite.hpp>
#include <boost/simd/function/simd/is_not_infinite.hpp>

#endif
