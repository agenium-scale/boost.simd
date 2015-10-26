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
#ifndef BOOST_SIMD_FUNCTION_REMAINDER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REMAINDER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the remainder of division.
    The return value is a0-n*a1, where n is the value a0/a1,
    rounded to the nearest integer (using round2even).

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = remainder(x, y);
    @endcode

    For floating point values the code is equivalent to:

    @code
    T r = x-divround2even(x, y)*y;
    @endcode

    @par Note:

    As r can be negative, @c remainder is not defined for unsigned types.

    @see mod, rem
    @par Alias

    @c drem


    @return      a value of the same type as the input.


**/
  template<typename T> auto remainder(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::remainder

      @see simd::remainder
    **/
    const boost::dispatch::functor<tag::remainder_> remainder = {};
  }
} }
#endif

#include <boost/simd/function/definition/remainder.hpp>
#include <boost/simd/arch/common/scalar/function/remainder.hpp>
//#include <boost/simd/arch/common/function/simd/remainder.hpp>

#endif
