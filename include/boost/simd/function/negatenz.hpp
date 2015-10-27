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
#ifndef BOOST_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns a0 multiplied by the signnz of a1
    The result is unspecified if a1 is NaN

    @par Semantic:

    @code
    T r = negatenz(a0,a1);
    @endcode

    is similar to:

    @code
    T r = a0*signnz(a1)
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T> auto negatenz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::negaten

z      @see simd::negaten
z    **/
    const boost::dispatch::functor<tag::negatenz_> negatenz = {};
  }
} }
#endif

#include <boost/simd/function/definition/negatenz.hpp>
#include <boost/simd/arch/common/generic/function/negatenz.hpp>
//#include <boost/simd/arch/common/function/simd/negatenz.hpp>

#endif
