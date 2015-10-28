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
#ifndef BOOST_SIMD_FUNCTION_PREV_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PREV_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the greatest representable value  strictly less than the parameter

    @par Semantic:

    @code
    T r = prev(x);
    @endcode

    computes the greatest value strictly less than x in type T

    @see next, nextafter, successor, predecessor

    @return a value of same type as the input

**/
  template<typename T> auto prev(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::prev

      @see simd::prev
    **/
    const boost::dispatch::functor<tag::prev_> prev = {};
  }
} }
#endif

#include <boost/simd/function/definition/prev.hpp>
#include <boost/simd/arch/common/scalar/function/prev.hpp>
//#include <boost/simd/arch/common/function/simd/prev.hpp>

#endif
