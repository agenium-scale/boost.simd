//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROUND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    round(x,n) rounds aways from 0 to n digits:

    @par semantic:
    For any given value @c x of type @c T and integer n :

    @code
    T r = round(x, n);
    @endcode

    is equivalent to

    @code
    T r = round(x*exp10(n)*exp10(-n));
    @endcode

    @par Note:

    n > 0: round to n digits to the right of the decimal point.

    n = 0: round to the nearest integer.

    n < 0: round to n digits to the left of the decimal point.

    aways from 0 means that half integer values are rounded to the nearest
    integer of greatest absolute value


    @return      a value of the same type as the input.


**/
  template<typename T> auto round(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      round(x,n) rounds aways from 0 to n digits:


      Function object tied to simd::round

      @see simd::round
    **/
    const boost::dispatch::functor<tag::round_> round = {};
  }
} }
#endif

#include <boost/simd/function/definition/round.hpp>
#include <boost/simd/arch/common/scalar/function/round.hpp>
#include <boost/simd/function/simd/round.hpp>

#endif
