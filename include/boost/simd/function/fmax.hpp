//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    Returns the maximum value, ignoring nans.

    This is a convenient alias of @ref maxnum
**/
  template<typename T> auto fmax(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the maximum value, ignoring nans.


      Function object tied to simd::fmax

      @see simd::fmax
    **/
    const boost::dispatch::functor<tag::fmax_> fmax = {};
  }
} }
#endif

#include <boost/simd/function/definition/fmax.hpp>
#include <boost/simd/arch/common/scalar/function/maxnum.hpp>
#include <boost/simd/function/simd/fmax.hpp>

#endif
