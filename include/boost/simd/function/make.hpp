//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-swar

    Build a value of type @c T from a list of scalar values of types @c Args

  **/
  template<typename T, typename.. Args> auto make(Args&&... args) {}
} }
#endif

#include <boost/simd/function/scalar/make.hpp>
#include <boost/simd/function/simd/make.hpp>

#endif
