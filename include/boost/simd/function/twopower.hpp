//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TWOPOWER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWOPOWER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes twopower value of its parameter.

  **/
  template<typename T> auto twopower(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::twopower

      @see simd::twopower
    **/
    const boost::dispatch::functor<tag::twopower_> twopower = {};
  }
} }
#endif

#include <boost/simd/function/definition/twopower.hpp>
#include <boost/simd/arch/common/scalar/function/twopower.hpp>
//#include <boost/simd/arch/common/function/simd/twopower.hpp>

#endif
