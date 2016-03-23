//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing modulus capabilities

    Computes the absolute value of its parameter.

    This is a convenient alias of @ref abs
  **/
  const boost::dispatch::functor<tag::modulus_> modulus = {};
} }
#endif

#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/simd/modulus.hpp>

#endif
