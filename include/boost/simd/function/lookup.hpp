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
#ifndef BOOST_SIMD_FUNCTION_LOOKUP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOOKUP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    shuffles the elements of x using indices in n

    @par Semantic:

    For every parameters of types respectively T, N:

    @code
    T r = lookup(x,n);
    @endcode

    is similar to:

    @code
    T0 r;
    for(size_t i=0; i < boost::simd::meta::cardinal_of<T0>::value; i++)
      r[i] = x[n[i]];
    @endcode



    @return a value of the same type as the first parameter

**/
  template<typename T, typename N> auto lookup(T const& x, N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      shuffles the elements of x using indices in n


      Function object tied to simd::lookup

      @see simd::lookup
    **/
    const boost::dispatch::functor<tag::lookup_> lookup = {};
  }
} }
#endif

#include <boost/simd/function/definition/lookup.hpp>
#include <boost/simd/arch/common/scalar/function/lookup.hpp>
//#include <boost/simd/arch/common/function/simd/lookup.hpp>

#endif
