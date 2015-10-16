//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-boolean

    Computes mask2logical value of its parameter.

  **/
  template<typename T> auto mask2logical(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::mask2logical

      @see simd::mask2logical
    **/
    const boost::dispatch::functor<tag::mask2logical_> mask2logical = {};
  }
} }
#endif

#include <boost/simd/function/definition/mask2logical.hpp>
#include <boost/simd/arch/common/generic/function/mask2logical.hpp>
//#include <boost/simd/arch/common/function/simd/mask2logical.hpp>

#endif
