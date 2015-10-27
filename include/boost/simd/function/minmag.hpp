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
    T r = minmag(a0,a1);
    @endcode

    is similar to:

    @code
    T r = abs(a0) < abs(a1) ? a0 : abs(a1) < abs(a0) ? a1 : min(a0, a1);
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T> auto minmag(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::minmag

      @see simd::minmag
    **/
    const boost::dispatch::functor<tag::minmag_> minmag = {};
  }
} }
#endif

#include <boost/simd/function/definition/minmag.hpp>
#include <boost/simd/arch/common/scalar/function/minmag.hpp>
//#include <boost/simd/arch/common/function/simd/minmag.hpp>

#endif
