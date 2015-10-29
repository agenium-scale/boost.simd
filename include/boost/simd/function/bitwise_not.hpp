//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_NOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_NOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return the bitwise bitwise_not of the entry
    Infix notation can be used with operator '~'

    This is a convenient alias of complement
**/
  template<typename T> auto bitwise_not(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      return the bitwise bitwise_not of the entry
      Infix notation can be used with operator '~'


      Function object tied to simd::bitwise_not

      @see simd::bitwise_not
    **/
    const boost::dispatch::functor<tag::bitwise_not_> bitwise_not = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_not.hpp>
#include <boost/simd/arch/common/scalar/function/complement.hpp>
#include <boost/simd/function/simd/bitwise_not.hpp>

#endif
