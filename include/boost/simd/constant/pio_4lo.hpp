//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_PIO_4LO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_PIO_4LO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    This constant is such that, for pairs of types (Tup, T)
    (namely (float,  double) and (double, long double)) the sum:

    abs(Tup(Pio_4lo<T>())+Tup(Pio_4<T>())-Pio_4\<Tup\>())  is  less than
    a few Eps<Tup>().

    This is used to improve accurracy when computing sums of the kind
    Pio_4 + x with x small,  by replacing them by Pio_4 + (Pio_4lo+x)

    @par Semantic:

    For type T:

    @code
    T r = Pio_4lo<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 3.061616997868383e-17
    else if T is float
      r = -2.1855694e-08
    @endcode

    @return a value of type T

**/
  template<typename T> T Pio_4lo();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      This constant is such that, for pairs of types (Tup, T)
      (namely (float,  double) and (double, long double)) the sum:

      Generate the  constant pio_4lo.

      @return The Pio_4lo constant for the proper type
    **/
    const boost::dispatch::functor<tag::pio_4lo_> pio_4lo = {};
  }
} }
#endif

#include <boost/simd/constant/definition/pio_4lo.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
