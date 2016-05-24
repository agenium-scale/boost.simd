//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_REDUCTION_HPP_INCLUDED
#define BOOST_SIMD_REDUCTION_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-reduction Reduction Functions

    Those functions provides algorithms for in-register reduction and prefix-scan operations.
    Those functions are usually only defined for SIMD types but may, in some cases like sum or
    product, have a valid scalar semantic.
  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-reduction Reduction Callable Objects
    Callable objects version of @ref group-reduction

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-reduction section.
  **/

} }

#include <boost/simd/function/all.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/compare_eq.hpp>
#include <boost/simd/function/compare_equal.hpp>
#include <boost/simd/function/compare_ge.hpp>
#include <boost/simd/function/compare_greater_equal.hpp>
#include <boost/simd/function/compare_greater.hpp>
#include <boost/simd/function/compare_less_equal.hpp>
#include <boost/simd/function/compare_less.hpp>
#include <boost/simd/function/compare_not_equal.hpp>
#include <boost/simd/function/cummax.hpp>
#include <boost/simd/function/cummin.hpp>
#include <boost/simd/function/cumprod.hpp>
#include <boost/simd/function/cumsum.hpp>
#include <boost/simd/function/dot.hpp>
#include <boost/simd/function/hmsb.hpp>
#include <boost/simd/function/is_included_c.hpp>
#include <boost/simd/function/is_included.hpp>
#include <boost/simd/function/is_simd_logical.hpp>
#include <boost/simd/function/maximum.hpp>
#include <boost/simd/function/minimum.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/function/none.hpp>
#include <boost/simd/function/posmax.hpp>
#include <boost/simd/function/posmin.hpp>
#include <boost/simd/function/prod.hpp>
#include <boost/simd/function/sum.hpp>

#endif

































































































































































