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
#ifndef BOOST_SIMD_FUNCTION_REMQUO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REMQUO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    @brief Remainder and part of quotient

    remquo computes the remainder and part of the quotient upon division of
    @c a0 by @c a1. By design, the value of the remainder is the same as that
    computed by the remainder function. The value of the computed quotient has
    the sign of @c a0/a1 and agrees with the actual quotient in at least the low
    order 3 bits.


**/
  template<typename T> auto remquo(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::remquo

      @see simd::remquo
    **/
    const boost::dispatch::functor<tag::remquo_> remquo = {};
  }
} }
#endif

#include <boost/simd/function/definition/remquo.hpp>
#include <boost/simd/arch/common/scalar/function/remquo.hpp>
//#include <boost/simd/arch/common/function/simd/remquo.hpp>

#endif
