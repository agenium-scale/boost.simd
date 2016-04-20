//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQR_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQR_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the saturated square of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = sqr_s(x);
    @endcode

    is similar to:

    @code
    T r = x*x > Valmax ? Valmax : x*x;
    @endcode

    @return      a value of the same type as the input.


**/
  template<typename T> auto sqr_s(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated square of its parameter.


      Function object tied to simd::sqr_s

      @see simd::sqr_s
    **/
    const boost::dispatch::functor<tag::sqr_s_> sqr_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sqr_s.hpp>
#include <boost/simd/function/simd/sqr_s.hpp>

#endif
