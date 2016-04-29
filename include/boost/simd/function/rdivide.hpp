//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RDIVIDE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RDIVIDE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing rdivide capabilities

    Computes  the truncated saturated division of its parameters.

    This is a convenient alias of @ref divides_s
  **/
  const boost::dispatch::functor<tag::rdivide_> rdivide = {};
} }
#endif

#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/simd/rdivide.hpp>

#endif
