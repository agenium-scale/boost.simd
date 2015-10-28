//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
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
    T r = (is_nan(x)) ? x :(x < zero) ? pi : zero;
    @endcode

    @par Note:

    Returns 0 or \f$\pi\f$  (or Nan if and only if the input is Nan)
    according to the input sign,

    This function is the restriction to real numbers of the complex
    argument function.

    @par Alias

    angle

    @return      a value of the type T.
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

#include <boost/simd/function/definition/arg.hpp>
#include <boost/simd/arch/common/generic/function/arg.hpp>
//#include <boost/simd/arch/common/function/simd/arg.hpp>

#endif
