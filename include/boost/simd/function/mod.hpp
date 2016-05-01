//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MOD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MOD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing mod capabilities

    Computes the remainder of division.
    The return value is x-n*y, where n is the value x/y,
    truncated to \f$-\infty\f$.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = mod(x, y);
    @endcode

    The code is similar to:

    @code
    T r = x-div(floor, x, y)*y;
    @endcode

    @see remainder, rem,  modulo

  **/
  const boost::dispatch::functor<tag::mod_> mod = {};
} }
#endif

#include <boost/simd/function/scalar/mod.hpp>
#include <boost/simd/function/simd/mod.hpp>

#endif
