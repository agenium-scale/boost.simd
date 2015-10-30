//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

     Returns the minimum value, ignoring nans.

    This is a convenient alias of @ref minnum
**/
  template<typename T> auto fmin(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

       Returns the minimum value, ignoring nans.


      Function object tied to simd::fmin

      @see simd::fmin
    **/
    const boost::dispatch::functor<tag::fmin_> fmin = {};
  }
} }
#endif

#include <boost/simd/function/definition/fmin.hpp>
#include <boost/simd/arch/common/scalar/function/minnum.hpp>
#include <boost/simd/function/simd/fmin.hpp>

#endif
