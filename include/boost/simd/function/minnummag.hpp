//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINNUMMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINNUMMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the input value which have the least absolute value, ignoring nan.

    @par Semantic:

    @code
    T r = minnummag(x,y);
    @endcode

    is similar to:

    @code
    T r =  isnan(x) ? y : (isnan(y) ? x : minmag(x, y));;
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T> auto minnummag(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the input value which have the least absolute value, ignoring nan.


      Function object tied to simd::minnummag

      @see simd::minnummag
    **/
    const boost::dispatch::functor<tag::minnummag_> minnummag = {};
  }
} }
#endif

#include <boost/simd/function/definition/minnummag.hpp>
#include <boost/simd/arch/common/scalar/function/minnummag.hpp>
#include <boost/simd/function/simd/minnummag.hpp>

#endif
