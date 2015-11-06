//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASECH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASECH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Returns the hyperbolic secant argument \f$\mathop{\textrm{acosh}}(1/x)\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asech(x);
    @endcode

    is similar to:

    @code
    T r = acosh(rec(x));
    @endcode

    @see acosh, cosh, rec

    @return a value of the same type as the parameter

**/
  template<typename T> auto asech(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic secant argument \f$\mathop{\textrm{acosh}}(1/x)\f$


      Function object tied to simd::asech

      @see simd::asech
    **/
    const boost::dispatch::functor<tag::asech_> asech = {};
  }
} }
#endif

#include <boost/simd/function/scalar/asech.hpp>
#include <boost/simd/function/simd/asech.hpp>

#endif
