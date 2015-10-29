//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHLI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHLI_HPP_INCLUDED

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
  template<typename T> auto shli(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      return left shift of the first operand by the second
      that must be of integer type and of the same number
      of elements as the first parameter
      Infix notation can be used with operator '<<'


      Function object tied to simd::shli

      @see simd::shli
    **/
    const boost::dispatch::functor<tag::shli_> shli = {};
  }
} }
#endif

#include <boost/simd/function/definition/shli.hpp>
#include <boost/simd/arch/common/scalar/function/shift_left.hpp>
#include <boost/simd/function/simd/shli.hpp>

#endif
