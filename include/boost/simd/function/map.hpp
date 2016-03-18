//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing map capabilities

   TODO- Computes map value of its parameter.

  **/
  const boost::dispatch::functor<tag::map_> map = {};
} }
#endif

#include <boost/simd/function/scalar/map.hpp>
#include <boost/simd/function/simd/map.hpp>

#endif
