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
#ifndef BOOST_SIMD_FUNCTION_SHL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return left shift of the first operand by the second
    that must be of integer type and of the same number
    of elements as the first parameter
    Infix notation can be used with operator '<<'

    This is a convenient alias of shift_left
**/
  template<typename T> auto shl(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      return left shift of the first operand by the second
      that must be of integer type and of the same number
      of elements as the first parameter
      Infix notation can be used with operator '<<'


      Function object tied to simd::shl

      @see simd::shl
    **/
    const boost::dispatch::functor<tag::shl_> shl = {};
  }
} }
#endif

#include <boost/simd/function/definition/shl.hpp>
#include <boost/simd/arch/common/scalar/function/shift_left.hpp>
#include <boost/simd/function/simd/shl.hpp>

#endif
