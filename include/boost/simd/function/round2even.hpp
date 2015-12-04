//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROUND2EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the rounded to even value of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = round2even(x);
    @endcode

    Returns the nearest integer to x.

    @par Note:

    to even means that half integer values are rounded to the nearest
    even value

    @par Alias:
    @c rint


    @return      a value of the same type as the input.


**/
  template<typename T> auto round2even(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the rounded to even value of its parameter.


      Function object tied to simd::round2even

      @see simd::round2even
    **/
    const boost::dispatch::functor<tag::round2even_> round2even = {};
  }
} }
#endif

#include <boost/simd/function/definition/round2even.hpp>
#include <boost/simd/arch/common/scalar/function/round2even.hpp>
#include <boost/simd/function/simd/round2even.hpp>

#endif
