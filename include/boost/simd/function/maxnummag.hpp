//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAXNUMMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAXNUMMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the input value which have the greatest absolute value, ignoring nan.

    @par Semantic:

    @code
    T r = maxnummag(a0,a1);
    @endcode

    is similar to:

    @code
    T r = isnan(a0) ? a1 : (isnan(a1) ? a0 : maxmag(a0, a1));
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T> auto maxnummag(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::maxnummag

      @see simd::maxnummag
    **/
    const boost::dispatch::functor<tag::maxnummag_> maxnummag = {};
  }
} }
#endif

#include <boost/simd/function/definition/maxnummag.hpp>
#include <boost/simd/arch/common/scalar/function/maxnummag.hpp>
//#include <boost/simd/arch/common/function/simd/maxnummag.hpp>

#endif
