//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REMROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REMROUND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the remainder of division.
    The return value is a0-n*a1, where n is the value a0/a1,
    rounded toward infinity.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = remround(x, y);
    @endcode

    For floating point values the code is equivalent to:

    @code
    T r = x-divround(x, y)*y;
    @endcode


    @return      a value of the same type as the input.


**/
  template<typename T> auto remround(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::remround

      @see simd::remround
    **/
    const boost::dispatch::functor<tag::remround_> remround = {};
  }
} }
#endif

#include <boost/simd/function/definition/remround.hpp>
#include <boost/simd/arch/common/generic/function/remround.hpp>
//#include <boost/simd/arch/common/function/simd/remround.hpp>

#endif
