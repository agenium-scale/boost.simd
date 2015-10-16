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
#ifndef BOOST_SIMD_FUNCTION_MINMOD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINMOD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes minmod value of its parameter.

  **/
  template<typename T> auto minmod(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::minmod

      @see simd::minmod
    **/
    const boost::dispatch::functor<tag::minmod_> minmod = {};
  }
} }
#endif

#include <boost/simd/function/definition/minmod.hpp>
#include <boost/simd/arch/common/scalar/function/minmod.hpp>
//#include <boost/simd/arch/common/function/simd/minmod.hpp>

#endif
