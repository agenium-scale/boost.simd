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
#ifndef BOOST_SIMD_FUNCTION_TOUINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOUINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes touint value of its parameter.

  **/
  template<typename T> auto touint(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::touint

      @see simd::touint
    **/
    const boost::dispatch::functor<tag::touint_> touint = {};
  }
} }
#endif

#include <boost/simd/function/definition/touint.hpp>
#include <boost/simd/arch/common/scalar/function/touint.hpp>
//#include <boost/simd/arch/common/function/simd/touint.hpp>

#endif
