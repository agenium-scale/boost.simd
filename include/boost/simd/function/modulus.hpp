//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MODULUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MODULUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes the absolute value of its parameter.

    This is a convenient alias of @ref abs
  **/
  template<typename T> auto modulus(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the absolute value of its parameter.


      Function object tied to simd::modulus

      @see simd::modulus
    **/
    const boost::dispatch::functor<tag::modulus_> modulus = {};
  }
} }
#endif

#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/simd/modulus.hpp>

#endif
