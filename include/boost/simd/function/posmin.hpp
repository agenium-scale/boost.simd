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
#ifndef BOOST_SIMD_FUNCTION_POSMIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POSMIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-reduction

    Computes posmin value of its parameter.

  **/
  template<typename T> auto posmin(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::posmin

      @see simd::posmin
    **/
    const boost::dispatch::functor<tag::posmin_> posmin = {};
  }
} }
#endif

#include <boost/simd/function/definition/posmin.hpp>
#include <boost/simd/arch/common/scalar/function/posmin.hpp>
//#include <boost/simd/arch/common/function/simd/posmin.hpp>

#endif
