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
#ifndef BOOST_SIMD_FUNCTION_IS_ORD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_ORD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-predicates

    Computes is_ord value of its parameter.

  **/
  template<typename T> auto is_ord(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_ord

      @see simd::is_ord
    **/
    const boost::dispatch::functor<tag::is_ord_> is_ord = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_ord.hpp>
#include <boost/simd/arch/common/scalar/function/is_ord.hpp>
//#include <boost/simd/arch/common/function/simd/is_ord.hpp>

#endif
