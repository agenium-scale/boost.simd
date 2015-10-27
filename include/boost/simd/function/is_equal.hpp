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
#ifndef BOOST_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    Returns True or False
    according a0 and a1 are equal or not. Infix notation can be used with operator '=='

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = is_equal(a0,a1);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = a0 == a1;
    @endcode

    @par Alias:
    @c eq, @c is_eq

    @see  is_not_equal, is_eqz, is_equal_with_equal_nans


    @return a logical value

**/
  template<typename T> auto is_equal(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::is_equal

      @see simd::is_equal
    **/
    const boost::dispatch::functor<tag::is_equal_> is_equal = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_equal.hpp>
#include <boost/simd/arch/common/scalar/function/is_equal.hpp>
//#include <boost/simd/arch/common/function/simd/is_equal.hpp>

#endif
