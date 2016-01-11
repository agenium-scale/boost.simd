//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SWAR_HPP_INCLUDED
#define BOOST_SIMD_SWAR_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-swar Intra register Functions

    Those functions provides algorithms for interleaving, aggregation, splitting and, more
    generally, wide registers sub-element manipulation. Those functions are usually only
    defined for SIMD types but may, in some cases, have a valid scalar semantic.
  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-swar Intra register Callable Objects
    Callable objects version of @ref group-swar

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-swar section.
  **/

} }

#include <boost/simd/function/broadcast.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/deinterleave_second.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/function/group.hpp>
#include <boost/simd/function/groups.hpp>
#include <boost/simd/function/lookup.hpp>
#include <boost/simd/function/reverse.hpp>
#include <boost/simd/function/sort.hpp>
#include <boost/simd/function/splatted_maximum.hpp>
#include <boost/simd/function/splatted_minimum.hpp>
#include <boost/simd/function/splatted_prod.hpp>
#include <boost/simd/function/splatted_sum.hpp>
#include <boost/simd/function/split.hpp>

#endif
