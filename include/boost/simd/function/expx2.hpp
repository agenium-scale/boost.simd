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
#ifndef BOOST_SIMD_FUNCTION_EXPX2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPX2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes expx2 value of its parameter.

  **/
  template<typename T> auto expx2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::expx2

      @see simd::expx2
    **/
    const boost::dispatch::functor<tag::expx2_> expx2 = {};
  }
} }
#endif

#include <boost/simd/function/definition/expx2.hpp>
#include <boost/simd/arch/common/scalar/function/expx2.hpp>
#include <boost/simd/function/simd/expx2.hpp>

#endif
