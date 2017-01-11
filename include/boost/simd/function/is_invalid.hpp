//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_INVALID_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_INVALID_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicatesq

    This function object returns @ref True if x is inf, -inf or nan else returns @ref False

    @par Semantic:

    @code
    auto r = is_invalid(x);
    @endcode

    is similar to:

    @code
    auto r = x-x != 0;
    @endcode

    @par Alias:
    @c is_not_finite


   @par Example:

     @snippet is_invalid.cpp is_invalid

   @par Possible output:

     @snippet is_invalid.txt is_invalid

  **/
  as_logical_t<Value> is_invalid(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/is_invalid.hpp>
#include <boost/simd/function/simd/is_invalid.hpp>

#endif
