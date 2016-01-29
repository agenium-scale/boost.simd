//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REALLOG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REALLOG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes reallog value of its parameter.

  **/
  template<typename T> auto reallog(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::reallog

      @see simd::reallog
    **/
    const boost::dispatch::functor<tag::reallog_> reallog = {};
  }
} }
#endif

#include <boost/simd/function/scalar/reallog.hpp>
#include <boost/simd/function/simd/reallog.hpp>

#endif
