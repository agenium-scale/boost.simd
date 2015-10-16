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
#ifndef BOOST_SIMD_FUNCTION_TOUINTS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOUINTS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes touints value of its parameter.

  **/
  template<typename T> auto touints(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::touints

      @see simd::touints
    **/
    const boost::dispatch::functor<tag::touints_> touints = {};
  }
} }
#endif

#include <boost/simd/function/definition/touints.hpp>
#include <boost/simd/arch/common/scalar/function/touints.hpp>
//#include <boost/simd/arch/common/function/simd/touints.hpp>

#endif
