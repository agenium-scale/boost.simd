//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GENMASK_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GENMASK_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-bitwise
    Function object implementing genmask capabilities

    Returns a mask of bits. All ones if the
    input element is non @ref Zero else all zeros.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = genmask(x);
    @endcode

    is similar to

    @code
    T r = x ? Allbits : Zero;
    @endcode

    @par Alias:
    @c if_allbits_else_zero

    @see if_allbits_else

  **/
  const boost::dispatch::functor<tag::genmask_> genmask = {};
} }
#endif

#include <boost/simd/function/scalar/genmask.hpp>
#include <boost/simd/function/simd/genmask.hpp>

#endif
