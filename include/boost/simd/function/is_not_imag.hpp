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
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_IMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_IMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-predicates

    Computes is_not_imag value of its parameter.

  **/
  template<typename T> auto is_not_imag(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_not_imag

      @see simd::is_not_imag
    **/
    const boost::dispatch::functor<tag::is_not_imag_> is_not_imag = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_not_imag.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_imag.hpp>
#include <boost/simd/arch/common/generic/function/is_not_imag.hpp>
//#include <boost/simd/arch/common/function/simd/is_not_imag.hpp>

#endif
