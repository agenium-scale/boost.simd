//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGSPACE_ADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGSPACE_ADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes logspace_add value of its parameter.

  **/
  template<typename T> auto logspace_add(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::logspace_add

      @see simd::logspace_add
    **/
    const boost::dispatch::functor<tag::logspace_add_> logspace_add = {};
  }
} }
#endif

#include <boost/simd/function/definition/logspace_add.hpp>
#include <boost/simd/arch/common/scalar/function/logspace_add.hpp>
#include <boost/simd/function/simd/logspace_add.hpp>

#endif
