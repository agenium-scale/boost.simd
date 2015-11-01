//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REALPOW_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REALPOW_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes realpow value of its parameter.

  **/
  template<typename T> auto realpow(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::realpow

      @see simd::realpow
    **/
    const boost::dispatch::functor<tag::realpow_> realpow = {};
  }
} }
#endif

#include <boost/simd/function/definition/realpow.hpp>
#include <boost/simd/arch/common/scalar/function/realpow.hpp>
#include <boost/simd/function/simd/realpow.hpp>

#endif
