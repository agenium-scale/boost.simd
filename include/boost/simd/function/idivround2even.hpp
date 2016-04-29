//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IDIVROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IDIVROUND2EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing idivround2even capabilities

    Computes the integer conversion of the rounded to even
    division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = idivround2even_(x, y);
    @endcode

    The code is similar to:

    @code
    as_integer_t<T> r = toint_s(round2even(x/y));
    @endcode

    If y is @ref Zero, it returns @ref Valmax (resp. @ref Valmin)
    if x is positive (resp. negative) and 0 if x is @ref Zero.

    @see toint_s, round2even

  **/
  const boost::dispatch::functor<tag::idivround2even_> idivround2even = {};
} }
#endif

#include <boost/simd/function/scalar/idivround2even.hpp>
#include <boost/simd/function/simd/idivround2even.hpp>

#endif
