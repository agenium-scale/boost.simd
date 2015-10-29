//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEQ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEQ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    Returns True if x and y are not equal else False.
    Infix notation can be used with operator '!='.


    This is a convenient alias of is_not_equal
**/
  template<typename T> auto neq(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Returns True if x and y are not equal else False.
      Infix notation can be used with operator '!='.


      Function object tied to simd::neq

      @see simd::neq
    **/
    const boost::dispatch::functor<tag::neq_> neq = {};
  }
} }
#endif

#include <boost/simd/function/definition/neq.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_equal.hpp>
#include <boost/simd/function/simd/neq.hpp>

#endif
