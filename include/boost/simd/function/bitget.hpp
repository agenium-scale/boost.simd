//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITGET_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITGET_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the value of the ith bit in x as an unsigned integer

    @par semantic:
    For any given value @c x of type @c T, i  of type @c I:

    @code
    as_integer_t<T> r = bitget(x, i);
    @endcode

    r contains is 0 or \f$2^i\f$ according to the fact the ith bit of x is 0 or 1

    @see  bitset

    @return a value of the unsigned integer type associated to the first input.


**/
  template<typename T, typename I> auto bitget(T const& x, I const& i) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the value of th ith bit in x as an unsigned integer


      Function object tied to simd::bitget

      @see simd::bitget
    **/
    const boost::dispatch::functor<tag::bitget_> bitget = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitget.hpp>
#include <boost/simd/arch/common/generic/function/bitget.hpp>
#include <boost/simd/function/simd/bitget.hpp>

#endif
