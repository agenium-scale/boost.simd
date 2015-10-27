//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POPCNT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POPCNT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the number of bit sets in the input.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T, unsigned> r = popcnt(x);
    @endcode

    @see  clz, ctz

    @return      a value of the unsigned integer
                 type associated to the input.


**/
  template<typename T> auto popcnt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::popcnt

      @see simd::popcnt
    **/
    const boost::dispatch::functor<tag::popcnt_> popcnt = {};
  }
} }
#endif

#include <boost/simd/function/definition/popcnt.hpp>
#include <boost/simd/arch/common/scalar/function/popcnt.hpp>
//#include <boost/simd/arch/common/function/simd/popcnt.hpp>

#endif
