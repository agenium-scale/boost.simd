//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_ANDNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    The operands must share the same @ref cardinal_of value.

    return the logical and of the first parameter and of the negation the second parameter.

    The operands must share the same @ref cardinal_of value.

    The result type is logical type associated to the first parameter.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = logical_andnot(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = x && !y;
    @endcode

    @par Alias:
    @c l_andnot

    @see  logical_or, logical_xor, logical_notand,
    logical_and, logical_notor, logical_ornot, logical_not

    @return  a value of the logical type associated to the first parameter

**/
 template<typename T1, typename T2> auto logical_andnot(T1 const& x, T2 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      The operands must share the same @ref cardinal_of value.


      Function object tied to simd::logical_andnot

      @see simd::logical_andnot
    **/
    const boost::dispatch::functor<tag::logical_andnot_> logical_andnot = {};
  }
} }
#endif

#include <boost/simd/function/definition/logical_andnot.hpp>
#include <boost/simd/arch/common/scalar/function/logical_andnot.hpp>
#include <boost/simd/function/simd/logical_andnot.hpp>

#endif
