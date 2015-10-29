//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the rounded to even value of its parameter.

    This is a convenient alias of round2even
**/
  template<typename T> auto rint(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the rounded to even value of its parameter.


      Function object tied to simd::rint

      @see simd::rint
    **/
    const boost::dispatch::functor<tag::rint_> rint = {};
  }
} }
#endif

#include <boost/simd/function/definition/rint.hpp>
#include <boost/simd/arch/common/scalar/function/round2even.hpp>
#include <boost/simd/function/simd/rint.hpp>

#endif
