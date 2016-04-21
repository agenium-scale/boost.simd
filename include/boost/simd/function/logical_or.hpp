//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_OR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_OR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-operator
    Function object implementing logical_or capabilities

    return the logical or of the two parameters

    The operands must share the same @ref cardinal_of value.

    Infix notation can be used with operator '||'

    @par Semantic:

    For every parameters of types respectively T1, T2:

    @code
    as_logical_t<T1> r = logical_or(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T1> r = x || y;
    @endcode

    @par Alias:
    @c l_or

    @see  logical_and, logical_xor, logical_notand,
    logical_andnot, logical_notor, logical_ornot, logical_not

  **/
  const boost::dispatch::functor<tag::logical_or_> logical_or = {};
} }
#endif

#include <boost/simd/function/scalar/logical_or.hpp>
#include <boost/simd/function/simd/logical_or.hpp>

#endif
