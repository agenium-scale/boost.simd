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
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_OR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_OR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return the logical or of the two parameters

    The operands must share the same Cardinal_of value.

    Infix notation can be used with operator '||'

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = logical_or(a0,a1);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = a0 || a1;
    @endcode

    @par Alias:
    @c l_or

    @see  logical_and, logical_xor, logical_notand,
    logical_andnot, logical_notor, logical_ornot, logical_not


    @return  a value of the logical type associated to the first parameter

**/
  template<typename T1, typename T2> auto logical_or(T1 const& a0, T2 const& a1) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::logical_or

      @see simd::logical_or
    **/
    const boost::dispatch::functor<tag::logical_or_> logical_or = {};
  }
} }
#endif

#include <boost/simd/function/definition/logical_or.hpp>
#include <boost/simd/arch/common/scalar/function/logical_or.hpp>
//#include <boost/simd/arch/common/function/simd/logical_or.hpp>

#endif
