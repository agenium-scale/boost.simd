//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_IMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_IMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-predicates

    Computes is_imag value of its parameter.

  **/
  template<typename T> auto is_imag(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_imag

      @see simd::is_imag
    **/
    const boost::dispatch::functor<tag::is_imag_> is_imag = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_imag.hpp>
#include <boost/simd/arch/common/scalar/function/is_imag.hpp>
#include <boost/simd/arch/common/generic/function/is_imag.hpp>
//#include <boost/simd/arch/common/function/simd/is_imag.hpp>

#endif
