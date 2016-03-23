//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQRS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQRS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing sqrs capabilities

    Computes the saturated square of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = sqrs(x);
    @endcode

    is similar to:

    @code
    T r = x*x > Valmax ? Valmax : x*x;
    @endcode

  **/
  const boost::dispatch::functor<tag::sqrs_> sqrs = {};
} }
#endif

#include <boost/simd/function/scalar/sqrs.hpp>
#include <boost/simd/function/simd/sqrs.hpp>

#endif
