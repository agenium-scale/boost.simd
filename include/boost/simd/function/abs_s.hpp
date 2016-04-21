//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ABS_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ABS_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-arithmetic

    Computes the saturated abs_olute value of its parameter.
    The result is always positive or 0.

    @par Semantic

    For any value @c x of type @c T,

    @code
    T r = abs_s(x);
    @endcode

    is equivalent to:

    @code
    T r = (x == Valmin) ? Valmax : (x < T(0) ? -x : x);
    @endcode

    @par Note:

    For integral types, the function always returns a positive value of the same type as the
    entry. For floating types @ref Nan is the obvious and lone exception to this rule.

    @par Note
    This functor is generally equivalent to @c abs_ functor except for signed integer
    types for which \c abs_s(@ref Valmin) is  @ref Valmax.

    @see  abs_, sqr_abs_s, sqr_s

    @param x value whose abs_olute value will be returned

    @return The  saturated abs_olute value of the parameter.
  **/
  template<typename T> auto abs_s(T const& x);

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated abs_olute value of its parameter.


      Function object tied to boost::simd::abs_s

      @see abs_
    **/
    const boost::dispatch::functor<tag::abs_s_> abs_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/abs_s.hpp>
#include <boost/simd/function/simd/abs_s.hpp>

#endif
