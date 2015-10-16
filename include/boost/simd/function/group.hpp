//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GROUP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GROUP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes group value of its parameter.

  **/
  template<typename T> auto group(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::group

      @see simd::group
    **/
    const boost::dispatch::functor<tag::group_> group = {};
  }
} }
#endif

#include <boost/simd/function/definition/group.hpp>
#include <boost/simd/arch/common/scalar/function/group.hpp>
//#include <boost/simd/arch/common/function/simd/group.hpp>

#endif
