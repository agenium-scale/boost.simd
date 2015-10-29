//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_GE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according x is greater or equal to y or not.

    Infix notation can be used with operator '>='.

    This is a convenient alias of is_greater_equal
**/
  template<typename T> auto is_ge(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True or False according x is greater or equal to y or not.


      Function object tied to simd::is_ge

      @see simd::is_ge
    **/
    const boost::dispatch::functor<tag::is_ge_> is_ge = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_ge.hpp>
#include <boost/simd/arch/common/scalar/function/is_greater_equal.hpp>
#include <boost/simd/function/simd/is_ge.hpp>

#endif
