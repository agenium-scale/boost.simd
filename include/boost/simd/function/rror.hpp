//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RROR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RROR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the first entry rotated right or left
    by the absolute value of the second entry,
    according to its sign.

    @par semantic:
    For any given value @c x of type @c T, n  of type @c I:

    @code
    T r = rror(x, n);
    @endcode

    @par Note
    This function asserts if the integral parameter is out of range

    @return      a value of the same type as the first input.


**/
  template<typename T, template N> auto rror(T const& x,  N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::rror

      @see simd::rror
    **/
    const boost::dispatch::functor<tag::rror_> rror = {};
  }
} }
#endif

#include <boost/simd/function/definition/rror.hpp>
#include <boost/simd/arch/common/scalar/function/rror.hpp>
//#include <boost/simd/arch/common/function/simd/rror.hpp>

#endif
