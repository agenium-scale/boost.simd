//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DECS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DECS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing decs capabilities

    Returns the entry minus 1, saturated in the entry type.

    This is a convenient alias of @ref minusone
  **/
  const boost::dispatch::functor<tag::decs_> decs = {};
} }
#endif

#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/simd/decs.hpp>

#endif
