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
#ifndef BOOST_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-boolean

    Computes if_one_else_zero value of its parameter.

  **/
  template<typename T> auto if_one_else_zero(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::if_one_else_zero

      @see simd::if_one_else_zero
    **/
    const boost::dispatch::functor<tag::if_one_else_zero_> if_one_else_zero = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_one_else_zero.hpp>
#include <boost/simd/arch/common/scalar/function/if_one_else_zero.hpp>
//#include <boost/simd/arch/common/function/simd/if_one_else_zero.hpp>

#endif
