//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_HYPERBOLIC_HPP_INCLUDED
#define BOOST_SIMD_HYPERBOLIC_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-hyperbolic  Hyperbolic functions

    These functions provide scalar and SIMD versions of
    hyperbolic and inverse hyperbolic functions.
  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-hyperbolic Hyperbolic Callable Objects
    Callable objects version of @ref group-hyperbolic

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-hyperbolic section.
  **/
} }

#include <boost/simd/function/acosh.hpp>
#include <boost/simd/function/acoth.hpp>
#include <boost/simd/function/acsch.hpp>
#include <boost/simd/function/asech.hpp>
#include <boost/simd/function/asinh.hpp>
#include <boost/simd/function/atanh.hpp>
#include <boost/simd/function/cosh.hpp>
#include <boost/simd/function/coth.hpp>
#include <boost/simd/function/csch.hpp>
#include <boost/simd/function/sech.hpp>
#include <boost/simd/function/sinhc.hpp>
#include <boost/simd/function/sinhcosh.hpp>
#include <boost/simd/function/sinh.hpp>
#include <boost/simd/function/tanh.hpp>

#endif
