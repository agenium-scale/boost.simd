//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_XOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_XOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    return the logical xor of the first parameter and of the second parameter.

    The operands must share the same @ref cardinal_of value.

    The result type is logical type associated to the first parameter.


    @par semantic:
    For every parameters of types respectively T1, T2:

    @code
    as_logical_t<T1> r = logical_xor(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T1> r = !x != !y;
    @endcode

    @see  logical_or, logical_ornot, logical_notand,
    logical_andnot, logical_notor, logical_and, logical_not

    @return a logical value of the logical type associated to the input.

**/
  template<typename T1, typename T2> auto logical_xor(T1 const& x, T2 const& y) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      return the logical xor of the first parameter and of the second parameter.


      Function object tied to simd::logical_xor

      @see simd::logical_xor
    **/
    const boost::dispatch::functor<tag::logical_xor_> logical_xor = {};
  }
} }
#endif

#include <boost/simd/function/definition/logical_xor.hpp>
#include <boost/simd/arch/common/scalar/function/logical_xor.hpp>
#include <boost/simd/function/simd/logical_xor.hpp>

#endif
