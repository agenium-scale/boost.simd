//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-arithmetic
    Function object implementing rec capabilities

    Returns the inverse (reciprocal) of the entry.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = rec(x);
    @endcode

    The code is similar to:

    @code
    T r = T(1)/x;
    @endcode

    @par Note:
    Speed can be sometimes gained using rec(x, fast_) but fast means here
    that the computation is possibly done through some
    low precision intrinsic. The result can be not fully accurate.

  **/
  const boost::dispatch::functor<tag::rec_> rec = {};
} }
#endif

#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/simd/rec.hpp>

#endif
