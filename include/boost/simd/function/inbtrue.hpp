//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing inbtrue capabilities

    Returns the number of non @ref Zero elements of the input SIMD vector.

    @par Semantic:

    For every parameter of type T

    @code
    std::size_t r = inbtrue(x);
    @endcode

    is similar to:

    @code
    std::size_t r = sum(if_one_else_zero(x));
    @endcode

  **/
  const boost::dispatch::functor<tag::inbtrue_> inbtrue = {};
} }
#endif

#include <boost/simd/function/scalar/inbtrue.hpp>
#include <boost/simd/function/simd/inbtrue.hpp>

#endif
