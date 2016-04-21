//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing rint capabilities

    Computes the rounded to even value of its parameter.

    This is a convenient alias of @ref round2even
  **/
  const boost::dispatch::functor<tag::rint_> rint = {};
} }
#endif

#include <boost/simd/function/scalar/round2even.hpp>
#include <boost/simd/function/simd/rint.hpp>

#endif
