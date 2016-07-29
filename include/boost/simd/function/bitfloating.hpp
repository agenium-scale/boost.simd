//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITFLOATING_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITFLOATING_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing bitfloating capabilities

    Transform a pattern of bits stored in an integer value
    in a floating point with different formulas according to
    the integer @ref bitofsign (converse of @ref bitinteger)

    @par Semantic:

    @code
    as_floating_t<T> r = bitfloating(x);
    @endcode

    is similar to:

    @code
    as_floating<T> r =  bitwise_cast<as_floating<T>>(x >=0 ? x : Signmask<T>()-x);
    @endcode

    @par Note:
    This is an utility function related to the computation of
    floating successors or predecessors.

    @see next, prev, successor,  predecessor,  nextafter

  **/
  as_floating_t<T> bitfloating(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/bitfloating.hpp>
#include <boost/simd/function/simd/bitfloating.hpp>

#endif
