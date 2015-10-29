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
#ifndef BOOST_SIMD_FUNCTION_AVERAGE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_AVERAGE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
                  {
  /*!
    @ingroup group-arithmetic

    Computes the arithmetic mean of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = average(x, y);
    @endcode

    For floating point values the code is equivalent to:

    @code
    T r = (x+y)/T(2);
    @endcode

    for integer types  it returns a rounded value at a distance guaranteed
    less or equal to 0.5 of the average floating value,  but can differ
    of one unity from the truncation given by (x1+x2)/T(2).

    @par Note:

    This function does not overflow.

    @see meanof

    @return      a value of the same type as the input.
  **/
  template<typename T> auto average(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the arithmetic mean of its parameters.


      Function object tied to simd::average

      @see simd::average
    **/
    const boost::dispatch::functor<tag::average_> average = {};
  }
} }
#endif

#include <boost/simd/function/scalar/average.hpp>
#include <boost/simd/function/simd/average.hpp>

#endif
