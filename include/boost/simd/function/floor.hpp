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
#ifndef BOOST_SIMD_FUNCTION_FLOOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FLOOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the floor of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = floor(x);
    @endcode

    greatest integral value of type @c T less or equal to @c x.

    @see  ceil, round, round2even, trunc, ifloor

    @return      an integral value of the same type as the input.


**/
  template<typename T> auto floor(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::floor

      @see simd::floor
    **/
    const boost::dispatch::functor<tag::floor_> floor = {};
  }
} }
#endif

#include <boost/simd/function/definition/floor.hpp>
#include <boost/simd/arch/common/scalar/function/floor.hpp>
#include <boost/simd/arch/common/generic/function/floor.hpp>
//#include <boost/simd/arch/common/function/simd/floor.hpp>

#endif
