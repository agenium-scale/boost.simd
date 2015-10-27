//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

   TODO- Computes map value of its parameter.

  **/
  template<typename T> auto map(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::map

      @see simd::map
    **/
    const boost::dispatch::functor<tag::map_> map = {};
  }
} }
#endif

#include <boost/simd/function/definition/map.hpp>
#include <boost/simd/arch/common/scalar/function/map.hpp>
//#include <boost/simd/arch/common/function/simd/map.hpp>

#endif
