//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MULS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MULS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing muls capabilities

    Computes the saturated multiplication of the two inputs.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = muls(x, y);
    @endcode

    The code is similar to:

    @code
    T r = x*y
    @endcode

    But is saturated for integer types

  **/
  const boost::dispatch::functor<tag::muls_> muls = {};
} }
#endif

#include <boost/simd/function/scalar/muls.hpp>
#include <boost/simd/function/simd/muls.hpp>

#endif
