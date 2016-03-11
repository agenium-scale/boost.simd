//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_PIO_2LO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_PIO_2LO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    This constant is such that, for pairs of types (T, Tup)
    (namely (float,  double) and (double, long double)) the sum:

    abs(Tup(Pio_2lo<T>())+Tup(Pio_2<T>())-Pio_2\< Tup \>()) is  less than
    a few Eps<Tup>().


    This is used to improve accurracy when computing sums of the kind
    \f$\pi/2 + x\f$ with x small,  by replacing them by
    Pio_2 + (Pio_2lo + x)

    @par Semantic:

    For type T:

    @code
    T r = Pio_2lo<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 6.123233995736766e-17
    else if T is float
      r = -4.3711388e-08
    @endcode

    @return a value of type T

**/
  template<typename T> T Pio_2lo();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      This constant is such that, for pairs of types (T, Tup)
      (namely (float,  double) and (double, long double)) the sum:

      Generate the  constant pio_2lo.

      @return The Pio_2lo constant for the proper type
    **/
    const boost::dispatch::functor<tag::pio_2lo_> pio_2lo = {};
  }
} }
#endif

#include <boost/simd/constant/definition/pio_2lo.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
