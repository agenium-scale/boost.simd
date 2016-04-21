//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITOFSIGN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITOFSIGN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing bitofsign capabilities

    Returns a value of the same type as the input with all bits set to zero
    except the bit of sign which is preserved.

    Returns always @ref Zero for unsigned types

    @par Semantic:

    @code
    T r = bitofsign(x);
    @endcode

    for signed types is similar to:

    @code
    T r = x&SignMask;
    @endcode

    @see sign, signnz, is_negative, is_positive, Mzero, SignMask;

  **/
  const boost::dispatch::functor<tag::bitofsign_> bitofsign = {};
} }
#endif

#include <boost/simd/function/scalar/bitofsign.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>

#endif
