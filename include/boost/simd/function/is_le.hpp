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
#ifndef BOOST_SIMD_FUNCTION_IS_LE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True or @ref False depending on whether x is
    less than or equal to y or not.

    Infix notation can be used with operator '<='.

    This is a convenient alias of @ref is_less_equal
**/
  template<typename T> auto is_le(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False  depending on whether x is
      less than or equal to y or not.


      Function object tied to simd::is_le

      @see simd::is_le
    **/
    const boost::dispatch::functor<tag::is_le_> is_le = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_le.hpp>
#include <boost/simd/arch/common/scalar/function/is_less_equal.hpp>
#include <boost/simd/function/simd/is_le.hpp>

#endif
