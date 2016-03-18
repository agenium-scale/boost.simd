//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FMIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing fmin capabilities

     Returns the minimum value, ignoring nans.

    This is a convenient alias of @ref minnum
  **/
  const boost::dispatch::functor<tag::fmin_> fmin = {};
} }
#endif

#include <boost/simd/function/scalar/minnum.hpp>
#include <boost/simd/function/simd/fmin.hpp>

#endif
