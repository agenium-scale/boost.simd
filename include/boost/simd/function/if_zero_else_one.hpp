//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_zero_else_one capabilities

    If @c c is @ref True returns @ref Zero else returns @ref One .

    @par Semantic:

    For every parameter @c c of type @c C :

    @code
    auto r = if_zero_else_one(c);
    @endcode

    is similar to:

    @code
    auto r = c ? Zero : One;
    @endcode

    @par Note:

    The return type is generally @c C except in the case where @c C is <tt>as_logical_t<T></tt>. in which case
    the return type is @c T .

  **/
  Value if_zero_else_one(Value const& c);

  //@overload
  Value if_zero_else_one(LogicalValue const& c);
} }
#endif

#include <boost/simd/function/scalar/if_zero_else_one.hpp>
#include <boost/simd/function/simd/if_zero_else_one.hpp>

#endif
