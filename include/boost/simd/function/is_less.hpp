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
#ifndef BOOST_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    Returns True< or False according a0 is less than a1 or not.
   Infix notation can be used with operator '<'.


    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = is_less(a0,a1);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = a0 < a1;
    @endcode

    @par Alias:
    @c lt, @c is_lt

    @see  is_less_equal, is_ltz, is_nge, is_ngez


    @return a logical value

**/
  template<typename T> auto is_less(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::is_less

      @see simd::is_less
    **/
    const boost::dispatch::functor<tag::is_less_> is_less = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_less.hpp>
#include <boost/simd/arch/common/scalar/function/is_less.hpp>
//#include <boost/simd/arch/common/function/simd/is_less.hpp>

#endif
