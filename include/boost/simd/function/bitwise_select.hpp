//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the bitwise selection of bits from the second
    or third operand according to the setting of the bits
    of the first operand

    @par semantic:
    For any given value @c x, of type @c T1, @c y of type @c T2 and @c z of type @c T2
    of same memory size:

    @code
    T2 r = bitwise_select(x, y, z);
    @endcode

    The code is equivalent to:

    @code
    T2 r = (x&y)|(z&~y);
    @endcode

    @par Alias

    b_select


    @return      a value of the same type as the second input.


**/
  template<typename T> auto bitwise_select(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::bitwise_select

      @see simd::bitwise_select
    **/
    const boost::dispatch::functor<tag::bitwise_select_> bitwise_select = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_select.hpp>
#include <boost/simd/arch/common/generic/function/bitwise_select.hpp>
//#include <boost/simd/arch/common/function/simd/bitwise_select.hpp>

#endif
