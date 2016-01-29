//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHRA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHRA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return right shift of the first operand by the second
    that must be of integer type and of the same number
    of elements as the first parameter
    Infix notation can be used with operator '>>'

    This is a convenient alias of @ref shift_right
**/
  template<typename T> auto shra(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      return right shift of the first operand by the second
      that must be of integer type and of the same number
      of elements as the first parameter
      Infix notation can be used with operator '>>'


      Function object tied to simd::shra

      @see simd::shra
    **/
    const boost::dispatch::functor<tag::shra_> shra = {};
  }
} }
#endif

#include <boost/simd/function/scalar/shift_right.hpp>
#include <boost/simd/function/simd/shra.hpp>

#endif
