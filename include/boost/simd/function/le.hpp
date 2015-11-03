//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True<result_type>() or False<result_type>() depending on whether x is
    less than or equal to y or not.

    Infix notation can be used with operator '<='.

    This is a convenient alias of @ref is_less_equal
**/
  template<typename T> auto le(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True<result_type>() or False<result_type>() depending on whether x is
      less than or equal to y or not.


      Function object tied to simd::le

      @see simd::le
    **/
    const boost::dispatch::functor<tag::le_> le = {};
  }
} }
#endif

#include <boost/simd/function/definition/le.hpp>
#include <boost/simd/arch/common/scalar/function/is_less_equal.hpp>
#include <boost/simd/function/simd/le.hpp>

#endif
