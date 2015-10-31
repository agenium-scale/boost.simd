//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IROUND2EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the integer conversion of the round2even of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T> r = iround2even(x);
    @endcode

    is similar to:

    @code
    as_integer_t<T> r = toints(round2even(x));
    @endcode

    @par Note:
    Speed can be gained using iround2even(x, fast_) that uses @ref
    toint in place of @ref toints,  but be aware that large values can be not correctly converted
    and that invalid entries lead to undefined results

    @return an integral value of the integral type associated to the input.


**/
  template<typename T> auto iround2even(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the integer conversion of the round2even of its parameter.


      Function object tied to simd::iround2even

      @see simd::iround2even
    **/
    const boost::dispatch::functor<tag::iround2even_> iround2even = {};
  }
} }
#endif

#include <boost/simd/function/definition/iround2even.hpp>
#include <boost/simd/arch/common/generic/function/iround2even.hpp>
#include <boost/simd/function/simd/iround2even.hpp>

#endif
