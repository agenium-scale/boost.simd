//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ROR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-bitwise
    Function object implementing ror capabilities

    Returns the first entry rotated right
    by the absolute value of the second entry.

    @par semantic:
    For any given value @c x of type @c T, n  of type @c I:

    @code
    T r = ror(x, n);
    @endcode

    @par Note
    This function asserts if the integral parameter is out of range

    @see  rol, rror, rrol

  **/
  const boost::dispatch::functor<tag::ror_> ror = {};
} }
#endif

#include <boost/simd/function/scalar/ror.hpp>
#include <boost/simd/function/simd/ror.hpp>

#endif
