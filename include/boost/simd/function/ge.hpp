//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according x is greater or equal to y or not.

    Infix notation can be used with operator '>='.

    This is a convenient alias of is_greater_equal
**/
  template<typename T> auto ge(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True or False according x is greater or equal to y or not.


      Function object tied to simd::ge

      @see simd::ge
    **/
    const boost::dispatch::functor<tag::ge_> ge = {};
  }
} }
#endif

#include <boost/simd/function/definition/ge.hpp>
#include <boost/simd/arch/common/scalar/function/is_greater_equal.hpp>
#include <boost/simd/function/simd/ge.hpp>

#endif
