//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FABS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing fabs capabilities

    Computes the absolute value of its parameter.

    This is a convenient alias of @ref abs
  **/
  const boost::dispatch::functor<tag::fabs_> fabs = {};
} }
#endif

#include <boost/simd/function/scalar/fabs.hpp>
#include <boost/simd/function/simd/fabs.hpp>

#endif
