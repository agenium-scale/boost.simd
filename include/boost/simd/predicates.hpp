//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_PREDICATES_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-predicates Predicates functions

      These functions provide scalar and SIMD algorithms for testing properties of values.
      Tests such as checks for validity, infinity, sign and others are provided. As for @ref
      group-boolean, these functions handle and return typed logical types.
  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-predicates Predicates Callable Objects
    Callable objects version of @ref group-predicates

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-predicates section.
  **/
} }

#include <boost/simd/function/is_denormal.hpp>
#include <boost/simd/function/is_equal_with_equal_nans.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_even.hpp>
#include <boost/simd/function/is_finite.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/is_greater_equal.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_imag.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/is_less_equal.hpp>
#include <boost/simd/function/is_lessgreater.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_lez.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_ngez.hpp>
#include <boost/simd/function/is_ngtz.hpp>
#include <boost/simd/function/is_nlez.hpp>
#include <boost/simd/function/is_nltz.hpp>
#include <boost/simd/function/is_normal.hpp>
#include <boost/simd/function/is_not_denormal.hpp>
#include <boost/simd/function/is_not_equal_with_equal_nans.hpp>
#include <boost/simd/function/is_not_greater_equal.hpp>
#include <boost/simd/function/is_not_greater.hpp>
#include <boost/simd/function/is_not_imag.hpp>
#include <boost/simd/function/is_not_infinite.hpp>
#include <boost/simd/function/is_not_less_equal.hpp>
#include <boost/simd/function/is_not_less.hpp>
#include <boost/simd/function/is_not_nan.hpp>
#include <boost/simd/function/is_not_real.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/is_ord.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/is_real.hpp>
#include <boost/simd/function/is_unord.hpp>
#include <boost/simd/function/majority.hpp>

#endif

