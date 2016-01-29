//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FABS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes the absolute value of its parameter.

    This is a convenient alias of @ref abs
  **/
  template<typename T> auto fabs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the fabsolute value of its parameter.


      Function object tied to simd::fabs

      @see simd::fabs
    **/
    const boost::dispatch::functor<tag::fabs_> fabs = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fabs.hpp>
#include <boost/simd/function/simd/fabs.hpp>

#endif
