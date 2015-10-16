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
#ifndef BOOST_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes tenpower value of its parameter.

  **/
  template<typename T> auto tenpower(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::tenpower

      @see simd::tenpower
    **/
    const boost::dispatch::functor<tag::tenpower_> tenpower = {};
  }
} }
#endif

#include <boost/simd/function/definition/tenpower.hpp>
#include <boost/simd/arch/common/scalar/function/tenpower.hpp>
//#include <boost/simd/arch/common/function/simd/tenpower.hpp>

#endif
