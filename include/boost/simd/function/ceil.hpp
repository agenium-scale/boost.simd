//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CEIL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CEIL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

   Computes the ceil of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = ceil(x);
    @endcode

    computes the smallest integral value of type @c T greater or equal to @c x.

    @par Note

    ceil(x, std_) use the call to std::ceil from stdlibc++

    @see  floor, round, round2even, trunc, iceil

    @return      an integral value of the same type as the input.

  **/
  template<typename T> auto ceil(T const& x) {}

  namespace functional
  {
    /*!

    Computes the ceil of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = ceil(x);
    @endcode

    smallest integral value of type @c T greater or equal to @c x.

    @see  floor, round, round2even, trunc, iceil

    @return      an integral value of the same type as the input.


**/
    const boost::dispatch::functor<tag::ceil_> ceil = {};
  }
} }
#endif

#include <boost/simd/function/definition/ceil.hpp>
#include <boost/simd/arch/common/scalar/function/ceil.hpp>
#include <boost/simd/function/simd/ceil.hpp>

#endif
