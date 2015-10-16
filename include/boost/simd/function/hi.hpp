//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_HI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_HI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes hi value of its parameter.

  **/
  template<typename T> auto hi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::hi

      @see simd::hi
    **/
    const boost::dispatch::functor<tag::hi_> hi = {};
  }
} }
#endif

#include <boost/simd/function/definition/hi.hpp>
#include <boost/simd/arch/common/generic/function/hi.hpp>
//#include <boost/simd/arch/common/function/simd/hi.hpp>

#endif
