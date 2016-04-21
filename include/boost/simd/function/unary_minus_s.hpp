//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_UNARY_MINUS_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_UNARY_MINUS_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-arithmetic

    Computes the saturated unary_minus_olute value of its parameter.
    The result is always positive or 0.

    @par Semantic

    For any value @c x of type @c T,

    @code
    T r = unary_minus_s(x);
    @endcode

    is equivalent to:

    @code
    T r = (x == Valmin) ? Valmax : (x < T(0) ? -x : x);
    @endcode

    @par Note:

    For integral types, the function always returns a positive value of the same type as the
    entry. For floating types @ref Nan is the obvious and lone exception to this rule.

    @par Note
    This functor is generally equivalent to @c unary_minus_ functor except for signed integer
    types for which \c unary_minus_s(@ref Valmin) is  @ref Valmax.

    @see  unary_minus_, sqr_unary_minus_s, sqr_s

    @param x value whose unary_minus_olute value will be returned

    @return The  saturated unary_minus_olute value of the parameter.
  **/
  template<typename T> auto unary_minus_s(T const& x);

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated unary_minus_olute value of its parameter.


      Function object tied to boost::simd::unary_minus_s

      @see unary_minus_
    **/
    const boost::dispatch::functor<tag::unary_minus_s_> unary_minus_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/unary_minus_s.hpp>
#include <boost/simd/function/simd/unary_minus_s.hpp>

#endif
