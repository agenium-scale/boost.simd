//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing negs capabilities

    Computes the saturated negation of the input.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = negs(x);
    @endcode

    For floating the code is equivalent to:

    @code
    T r = -x
    @endcode

    @par Note:

    - For signed integral types negs(@ref Valmin) returns @ref Valmax.

    - For unsigned integral types negs always returns 0.

  **/
  const boost::dispatch::functor<tag::negs_> negs = {};
} }
#endif

#include <boost/simd/function/scalar/negs.hpp>
#include <boost/simd/function/simd/negs.hpp>

#endif
