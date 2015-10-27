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
#ifndef BOOST_SIMD_FUNCTION_NEXTAFTER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEXTAFTER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the next element in the a1 direction.
    \par
    rg if a1 is greater than a0 this is next(a0)
    rg if a1 is equal to a0 this is a0
    rg if a1 is less than a0 this is prev(a0)

    @par Semantic:

    @code
    T r = nextafter(x, y);
    @endcode

    is similar to:

    @code
    if (y >  x)  r = next(a0);
    else if (y == x)  r = a0;
    else if (y <  x)  r = prev(a0);
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T> auto nextafter(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::nextafter

      @see simd::nextafter
    **/
    const boost::dispatch::functor<tag::nextafter_> nextafter = {};
  }
} }
#endif

#include <boost/simd/function/definition/nextafter.hpp>
#include <boost/simd/arch/common/scalar/function/nextafter.hpp>
//#include <boost/simd/arch/common/function/simd/nextafter.hpp>

#endif
