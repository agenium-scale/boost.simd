//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ARG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ARG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes the angular orientation of its parameter.

    @par semantic:
    For any given value @c x of floating type @c T:

    @code
    T r = arg(x);
    @endcode

    is equivalent to:

    @code
    T r = (is_nan(x)) ? x : (is_negative(x)) ? Pi<T>() : Zero<T>();
    @endcode

    @par Note:

    - Returns \f$+0\f$ or \f$\pi\f$  (or @ref Nan if and only if the input is @ref Nan)
    according to the input @ref sign bit,

    - arg(x, use_signbit_) always returns \f$+0\f$ or \f$\pi\f$ taking into account the bit of sign
    even in the Nan case and is a bit speedier.

    - This function is the restriction to real numbers of the complex
    arg(ument) function.

    @par Alias:

    angle

    @see is_negative,  is_ltz,  Pi

    @return a value of the type T.
  **/
  template<typename T> auto arg(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the angular orientation of its parameter.


      Function object tied to simd::arg

      @see simd::arg
    **/
    const boost::dispatch::functor<tag::arg_> arg = {};
  }
} }
#endif

#include <boost/simd/function/scalar/arg.hpp>
#include <boost/simd/function/simd/arg.hpp>

#endif
