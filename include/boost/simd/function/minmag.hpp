//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the input value which have the least absolute value.

    @par Semantic:

    @code
    T r = minmag(x,y);
    @endcode

    is similar to:

    @code
    T r = abs(x) < abs(y) ? x : abs(y) < abs(x) ? y : min(x, y);
    @endcode

   @see min, minnummag, minnum


    @return a value of same type as the inputs

**/
  template<typename T> auto minmag(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the input value which have the least absolute value.


      Function object tied to simd::minmag

      @see simd::minmag
    **/
    const boost::dispatch::functor<tag::minmag_> minmag = {};
  }
} }
#endif

#include <boost/simd/function/definition/minmag.hpp>
#include <boost/simd/arch/common/scalar/function/minmag.hpp>
#include <boost/simd/function/simd/minmag.hpp>

#endif
