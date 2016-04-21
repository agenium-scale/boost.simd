//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TOFLOAT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOFLOAT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing tofloat capabilities

    Convert to floating point value.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_floating_t<T> r = tofloat(x);
    @endcode

    The code is similar to:

    @code
    as_floating_t<T> r = static_cast < as_floating_t<T> >(x)
    @endcode

  **/
  const boost::dispatch::functor<tag::tofloat_> tofloat = {};
} }
#endif

#include <boost/simd/function/scalar/tofloat.hpp>
#include <boost/simd/function/simd/tofloat.hpp>

#endif
