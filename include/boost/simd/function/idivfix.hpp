//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IDIVFIX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IDIVFIX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the integer conversion of the truncated division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = idivfix(x, y);
    @endcode

    The code is similar to:

    @code
    as_integer_t<T> r = toints(trunc(x/y));
    @endcode

    If y is @ref Zero, it returns @ref Valmax (resp. @ref Valmin)
    if x is positive (resp. negative) and 0 if x is @ref Zero.


    @see toints, trunc
    @return      a value of the integral type associated to the input.


**/
  template<typename T> auto idivfix(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the integer conversion of the truncated division of its parameters.


      Function object tied to simd::idivfix

      @see simd::idivfix
    **/
    const boost::dispatch::functor<tag::idivfix_> idivfix = {};
  }
} }
#endif

#include <boost/simd/function/definition/idivfix.hpp>
#include <boost/simd/arch/common/generic/function/idivfix.hpp>
#include <boost/simd/function/simd/idivfix.hpp>

#endif
