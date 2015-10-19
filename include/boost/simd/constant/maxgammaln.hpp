//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXGAMMALN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXGAMMALN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant maxgammaln which is the greatest valuefor whixh gammaln
    is computable in the current type.

@par Semantic:

    @code
    T r = Maxgammaln<T>();
    @endcode

    is similar to:

    @code
    if T is float
      T r = 2.035093e36f
    else if T is double
      T r = 2.556348e305
    @endcode

    @return The Maxgammaln constant for the proper type
  **/
  template<typename T> T Maxgammaln();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant maxgammaln.

      @return The Maxgammaln constant for the proper type
    **/
    const boost::dispatch::functor<tag::maxgammaln_> maxgammaln = {};
  }
} }
#endif

#include <boost/simd/constant/definition/maxgammaln.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
