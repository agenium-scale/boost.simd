//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FMAX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMAX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing fmax capabilities

    Returns the maximum value, ignoring nans.

    This is a convenient alias of @ref maxnum
  **/
  const boost::dispatch::functor<tag::fmax_> fmax = {};
} }
#endif

#include <boost/simd/function/scalar/maxnum.hpp>
#include <boost/simd/function/simd/fmax.hpp>

#endif
