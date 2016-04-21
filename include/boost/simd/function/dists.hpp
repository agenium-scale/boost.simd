//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DISTS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DISTS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing dists capabilities

    Computes the (saturated) absolute value of the difference of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = dists(x, y);
    @endcode

    is similar to:

    @code
    T r = abss(x-y);
    @endcode

    @par Note

    The result is never stricly negative moreover it satisfies the predicate

     @code  is_positive(dist(x, y)) || is_unord(x, y) @endcode

    For floating, it can of course be @ref Nan.

    @see  abss, ulpdist

  **/
  const boost::dispatch::functor<tag::dists_> dists = {};
} }
#endif

#include <boost/simd/function/scalar/dists.hpp>
#include <boost/simd/function/simd/dists.hpp>

#endif
