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
#ifndef BOOST_SIMD_FUNCTION_LOGSPACE_SUB_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGSPACE_SUB_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes logspace_sub value of its parameter.

  **/
  template<typename T> auto logspace_sub(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::logspace_sub

      @see simd::logspace_sub
    **/
    const boost::dispatch::functor<tag::logspace_sub_> logspace_sub = {};
  }
} }
#endif

#include <boost/simd/function/definition/logspace_sub.hpp>
#include <boost/simd/arch/common/scalar/function/logspace_sub.hpp>
#include <boost/simd/function/simd/logspace_sub.hpp>

#endif
