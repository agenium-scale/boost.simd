//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    TODO Put description here

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T0 r = comma(x,y);
    @endcode

    is similar to:

    @code
    T0 r = (x, y);
    @endcode



    @return a value of the same type as the second parameter

**/
  template<typename T> auto comma(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      TODO Put description here


      Function object tied to simd::comma

      @see simd::comma
    **/
    const boost::dispatch::functor<tag::comma_> comma = {};
  }
} }
#endif

#include <boost/simd/function/scalar/comma.hpp>
#include <boost/simd/function/simd/comma.hpp>

#endif
