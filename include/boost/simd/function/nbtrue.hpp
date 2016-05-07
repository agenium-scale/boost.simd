//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing nbtrue capabilities

    Returns the number of non @ref Zero elements of the input SIMD vector.

    @par Semantic:

    For every parameter of type T

    @code
    size_t r = nbtrue(x);
    @endcode

    is similar to:

    @code
    sizet r = size_t(sum(if_one_else_zero(x)));
    @endcode

  **/
  const boost::dispatch::functor<tag::nbtrue_> nbtrue = {};
} }
#endif

#include <boost/simd/function/scalar/nbtrue.hpp>
#include <boost/simd/function/simd/nbtrue.hpp>

#endif
