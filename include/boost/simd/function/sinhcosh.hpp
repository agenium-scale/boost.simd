//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINHCOSH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINHCOSH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Computes simultaneously (and more rapidly) the sinh and cosh of the input

    @par Semantic:

    @code
    T ch, sh
    sinhcosh(x, sh, ch);
    @endcode

    is similar to:

    @code
    T sh = sinh(x);
    T ch = cosh(x);
    @endcode


    @see  sinh, cosh


**/
  template<typename T> auto sinhcosh(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Computes simultaneously the sinh and cosh of the input


      Function object tied to simd::sinhcosh

      @see simd::sinhcosh
    **/
    const boost::dispatch::functor<tag::sinhcosh_> sinhcosh = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sinhcosh.hpp>
#include <boost/simd/function/simd/sinhcosh.hpp>

#endif
