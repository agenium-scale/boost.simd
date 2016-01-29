//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FAST_IROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_IROUND2EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes fast_iround2even value of its parameter.

  **/
  template<typename T> auto fast_iround2even(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes fast_iround2even value of its parameter.


      Function object tied to simd::fast_iround2even

      @see simd::fast_iround2even
    **/
    const boost::dispatch::functor<tag::fast_iround2even_> fast_iround2even = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fast_iround2even.hpp>
#include <boost/simd/function/simd/fast_iround2even.hpp>

#endif
