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
#ifndef BOOST_SIMD_FUNCTION_SUCCESSOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SUCCESSOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the n-th least element strictly greater than the parameter

    @par Semantic:

    @code
    T r = successor(x,n);
    @endcode

    computes the @c n-th least representable value strictly greater than x in its type.
    n must be positive or null.

    For integer it saturate at @c Valmax, for floating point numbers @c Inf
    strict successor are @c Nan.

    @return a value of same type as the inputs

**/
  template<typename T, typename N> auto successor(T const& x, N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::successor

      @see simd::successor
    **/
    const boost::dispatch::functor<tag::successor_> successor = {};
  }
} }
#endif

#include <boost/simd/function/definition/successor.hpp>
#include <boost/simd/arch/common/scalar/function/successor.hpp>
//#include <boost/simd/arch/common/function/simd/successor.hpp>

#endif
