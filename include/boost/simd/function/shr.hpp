//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the first entry logically shifted right
    by value of the second entry. If the second entry is negative
    the result is not defined.

    @par semantic:
    For any given value @c x of type @c T, n  of type @c I:

    @code
    T r = shr(x, n);
    @endcode

    @par Alias:

    @c shri

    @see  shift_right, shift_left, rshl, rshr, rol, ror

    @return      a value of the same type as the first input.


**/
  template<typename T, template N> auto shr(T const& x,  N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::shr

      @see simd::shr
    **/
    const boost::dispatch::functor<tag::shr_> shr = {};
  }
} }
#endif

#include <boost/simd/function/definition/shr.hpp>
#include <boost/simd/arch/common/scalar/function/shr.hpp>
//#include <boost/simd/arch/common/function/simd/shr.hpp>

#endif
