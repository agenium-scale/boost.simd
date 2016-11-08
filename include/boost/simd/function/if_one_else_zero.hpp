//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_one_else_zero capabilities

    If @c c is @ref True returns @ref One else returns @ref Zero .

    @par Semantic:

    For every parameter @c c of type @c C :

    @code
    auto r = if_one_else_zero(c);
    @endcode

    is similar to:

    @code
    auto r = c ? One : Zero;
    @endcode

    @par Note:

    The return type is generally @c C except in the case where @c C is <tt>as_logical_t<T></tt> in which case
    the return type is @c T .

  **/
  Value if_one_else_zero(Value const& c);

  //@overload
  Value if_one_else_zero(LogicalValue const& c);
} }
#endif

#include <boost/simd/function/scalar/if_one_else_zero.hpp>
#include <boost/simd/function/simd/if_one_else_zero.hpp>

#endif
