//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_NOTOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_NOTOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing logical_notor capabilities

    return the logical or of the negation of the first parameter and the second parameter.

    The operands must share the same @ref cardinal_of value.

    The result type is logical type associated to the first parameter.

    @par Semantic:

    For every parameters of types respectively T1, T2:

    @code
    as_logical_t<T1> r = logical_notor(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T1> r = !x || y;
    @endcode

    @par Alias:
    @c l_notor

    @see  logical_or, logical_xor, logical_notand,
    logical_andnot, logical_and, logical_ornot, logical_not

  **/
  const boost::dispatch::functor<tag::logical_notor_> logical_notor = {};
} }
#endif

#include <boost/simd/function/scalar/logical_notor.hpp>
#include <boost/simd/function/simd/logical_notor.hpp>

#endif
