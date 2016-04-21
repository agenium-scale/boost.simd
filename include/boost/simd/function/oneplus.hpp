//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ONEPLUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ONEPLUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing oneplus capabilities

    Returns the entry plus one.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = oneplus(x);
    @endcode

    The code is similar to:

    @code
    T r =  x+One<T>()
    @endcode

    @see inc, inc_s,  saturated_

    @par Alias

    inc

  **/
  const boost::dispatch::functor<tag::oneplus_> oneplus = {};
} }
#endif

#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/simd/function/simd/oneplus.hpp>

#endif
