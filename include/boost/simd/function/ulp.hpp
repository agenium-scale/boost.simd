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
#ifndef BOOST_SIMD_FUNCTION_ULP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ULP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the ulp distance to the nearest (distinct) element of the same type.

    @par Semantic:

    @code
    T r = ulp(x);
    @endcode

    is similar to:

    @code
    T r = min(x-prev(x), next(x)-x)/Eps<T>();
    @endcode

    @par Note
    ulp stands for Unit in the Last Place.


    @return a value of same type as the input

**/
  template<typename T> auto ulp(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the ulp distance to the nearest (distinct) element of the same type.


      Function object tied to simd::ulp

      @see simd::ulp
    **/
    const boost::dispatch::functor<tag::ulp_> ulp = {};
  }
} }
#endif

#include <boost/simd/function/definition/ulp.hpp>
#include <boost/simd/arch/common/scalar/function/ulp.hpp>
//#include <boost/simd/arch/common/function/simd/ulp.hpp>

#endif
