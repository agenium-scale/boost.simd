//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGNBIT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGNBIT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    True or false according to the bit of sign set or not set.

    This is a convenient alias of @ref is_negative.
  **/
  template<typename T> auto signbit(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the signbit value of its parameter.


      Function object tied to simd::signbit

      @see simd::signbit
    **/
    const boost::dispatch::functor<tag::signbit_> signbit = {};
  }
} }
#endif

#include <boost/simd/function/definition/signbit.hpp>
#include <boost/simd/arch/common/scalar/function/is_negative.hpp>
#include <boost/simd/function/simd/signbit.hpp>

#endif
