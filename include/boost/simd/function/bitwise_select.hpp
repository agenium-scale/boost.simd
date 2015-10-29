//==================================================================================================
/*!
  @file

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
    For any given value @c sel of type @c SEL, @c x of type @c T0 and @c y of type @c T1
    of same memory size:

    @code
    T0 r = bitwise_select(sel, x, y);
    @endcode

    The code is equivalent to:

    @code
    T1 r = (x&sel)|(y&~sel);
    @endcode

    @par Alias

    b_select


    @return      a value of the same type as the second input.


**/
  template<typename SEL typename T0, typename T1>
  auto bitwise_select(SEL const& sel, T0 const& x, T1 const& y );


  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the bitwise selection of bits from the second
      or third operand according to the setting of the bits
      of the first operand


      Function object tied to simd::bitwise_select

      @see simd::bitwise_select
    **/
    const boost::dispatch::functor<tag::bitwise_select_> bitwise_select = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_select.hpp>
#include <boost/simd/arch/common/generic/function/bitwise_select.hpp>
#include <boost/simd/function/simd/bitwise_select.hpp>

#endif
