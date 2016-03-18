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

    Returns the entry plus one, saturated in the entry type.
    If @c x is not @ref Nan, @c oneplus(x) is greater or equal to x.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = oneplus(x);
    @endcode

    The code is similar to:

    @code
    T r = (x == Valmax) ? x : inc(x)
    @endcode

    @see inc, plus, adds

    @par Alias

    incs

  **/
  const boost::dispatch::functor<tag::oneplus_> oneplus = {};
} }
#endif

#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/simd/function/simd/oneplus.hpp>

#endif
