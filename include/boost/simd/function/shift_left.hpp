//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return left shift of the first operand by the second
    that must be of integer type and of the same number
    of elements as the first parameter
    Infix notation can be used with operator '<<'

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T0 r = shift_left(a0,a1);
    @endcode

    is similar to:

    @code
    T0 r = a0 << a1;
    @endcode

    @par Alias:
    @c shl, @c shli

    @see  shift_right, shr, rshl, rshr, rol, ror


    @return a value of the same type as the second parameter

**/
  template<typename T> auto shift_left(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::shift_left

      @see simd::shift_left
    **/
    const boost::dispatch::functor<tag::shift_left_> shift_left = {};
  }
} }
#endif

#include <boost/simd/function/definition/shift_left.hpp>
#include <boost/simd/arch/common/scalar/function/shift_left.hpp>
//#include <boost/simd/arch/common/function/simd/shift_left.hpp>

#endif
