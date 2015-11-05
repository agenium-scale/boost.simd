//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    @return      a value of the same type as the first input.


**/
  template<typename T, template N> auto ror(T const& x,  N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the first entry rotated right
      by the absolute value of the second entry.


      Function object tied to simd::ror

      @see simd::ror
    **/
    const boost::dispatch::functor<tag::ror_> ror = {};
  }
} }
#endif

#include <boost/simd/function/definition/ror.hpp>
#include <boost/simd/arch/common/generic/function/ror.hpp>
#include <boost/simd/function/simd/ror.hpp>

#endif
