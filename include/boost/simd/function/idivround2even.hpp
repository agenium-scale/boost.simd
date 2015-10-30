//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IDIVROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IDIVROUND2EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the integer conversion of the rounded to even
    division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = idivround2even_(x, y);
    @endcode

    The code is similar to:

    @code
    as_integer_t<T> r = toints(round2even(x/y));
    @endcode

    If y is @ref Zero, it returns @ref Valmax (resp. @ref Valmin)
    if x is positive (resp. negative) and 0 if x is @ref Zero.

    @see toints, round2even

    @return      a value of the integral type associated to the input.


**/
  template<typename T> auto idivround2even(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the integer conversion of the rounded to even
      division of its parameters.


      Function object tied to simd::idivround2even

      @see simd::idivround2even
    **/
    const boost::dispatch::functor<tag::idivround2even_> idivround2even = {};
  }
} }
#endif

#include <boost/simd/function/definition/idivround2even.hpp>
#include <boost/simd/arch/common/generic/function/idivround2even.hpp>
#include <boost/simd/function/simd/idivround2even.hpp>

#endif
