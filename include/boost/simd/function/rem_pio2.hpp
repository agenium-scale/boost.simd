//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REM_PIO2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REM_PIO2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    Computes the remainder modulo \f$\pi/2\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r, rc;
    as_integer<T> n;
    n = rem_pio2<Range>(x, r);
    @endcode

    is similar to:

    @code
    as_integer<T> n = idivround2even(x, Pio_2<T>());
    T r =  remainder(x, Pio_2<T>());
    @endcode

    @par Note:

    The Range parameter is a type among big_,  medium_,  small_,  very_small_
    that allow to statically choose the computation process.


    @return  the remainder

**/
  template<typename T> auto rem_pio2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      Computes the remainder modulo \f$\pi/2\f$.


      Function object tied to simd::rem_pio2

      @see simd::rem_pio2
    **/
    const boost::dispatch::functor<tag::rem_pio2_> rem_pio2 = {};
  }
} }
#endif

#include <boost/simd/function/scalar/rem_pio2.hpp>
#include <boost/simd/function/simd/rem_pio2.hpp>

#endif
