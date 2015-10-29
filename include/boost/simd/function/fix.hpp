//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FIX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FIX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the truncation toward zero of its parameter.

    This is a convenient alias of trunc
**/
  template<typename T> auto fix(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the truncation toward zero of its parameter.


      Function object tied to simd::fix

      @see simd::fix
    **/
    const boost::dispatch::functor<tag::fix_> fix = {};
  }
} }
#endif

#include <boost/simd/function/definition/fix.hpp>
#include <boost/simd/arch/common/scalar/function/trunc.hpp>
#include <boost/simd/function/simd/fix.hpp>

#endif
