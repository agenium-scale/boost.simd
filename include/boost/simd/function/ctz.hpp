//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the bit count of trailing zeroes

    Finds the first bit set in x, and returns the index of that bit, 0 being
    the least significant bit index.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T,unsigned> r = ctz(x);
    @endcode

    @par Note

    return the number of bits of the entry if input is zero,
    which is an illegal bit index.

    @see  clz, popcnt

    @return An unsigned integral value containing the index of the first bit
            set in x.


**/
  template<typename T> auto ctz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns the bit count of trailing zeroes


      Function object tied to simd::ct

z      @see simd::ct
z    **/
    const boost::dispatch::functor<tag::ctz_> ctz = {};
  }
} }
#endif

#include <boost/simd/function/definition/ctz.hpp>
#include <boost/simd/arch/common/scalar/function/ctz.hpp>
//#include <boost/simd/arch/common/function/simd/ctz.hpp>

#endif
