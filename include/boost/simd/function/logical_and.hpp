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
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return the logical and of the two parameters
    the operands must of the same type
    Infix notation can be used with operator '&&'

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = logical_and(a0,a1);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = a0 && a1 ;
    @endcode

    @par Alias:
    @c l_and

    @see  logical_or, logical_xor, logical_notand,
    logical_andnot, logical_notor, logical_ornot, logical_not


    @return a value of the same type as the second parameter

**/
  template<typename T> auto logical_and(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::logical_and

      @see simd::logical_and
    **/
    const boost::dispatch::functor<tag::logical_and_> logical_and = {};
  }
} }
#endif

#include <boost/simd/function/definition/logical_and.hpp>
#include <boost/simd/arch/common/scalar/function/logical_and.hpp>
//#include <boost/simd/arch/common/function/simd/logical_and.hpp>

#endif
