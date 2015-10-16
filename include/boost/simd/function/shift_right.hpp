//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes shift_right value of its parameter.

  **/
  template<typename T> auto shift_right(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::shift_right

      @see simd::shift_right
    **/
    const boost::dispatch::functor<tag::shift_right_> shift_right = {};
  }
} }
#endif

#include <boost/simd/function/definition/shift_right.hpp>
#include <boost/simd/arch/common/scalar/function/shift_right.hpp>
//#include <boost/simd/arch/common/function/simd/shift_right.hpp>

#endif
