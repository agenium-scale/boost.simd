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
#ifndef BOOST_SIMD_FUNCTION_IS_INVALID_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_INVALID_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-predicates

    Computes is_invalid value of its parameter.

  **/
  template<typename T> auto is_invalid(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_invalid

      @see simd::is_invalid
    **/
    const boost::dispatch::functor<tag::is_invalid_> is_invalid = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_invalid.hpp>
#include <boost/simd/arch/common/scalar/function/is_invalid.hpp>
//#include <boost/simd/arch/common/function/simd/is_invalid.hpp>

#endif
