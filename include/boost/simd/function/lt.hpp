//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True< or False according x is less than y or not.
   Infix notation can be used with operator '<'.


    This is a convenient alias of @ref is_less
**/
  template<typename T> auto lt(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True< or False according x is less than y or not.
     Infix notation can be used with operator '<'.


      Function object tied to simd::lt

      @see simd::lt
    **/
    const boost::dispatch::functor<tag::lt_> lt = {};
  }
} }
#endif

#include <boost/simd/function/definition/lt.hpp>
#include <boost/simd/arch/common/scalar/function/is_less.hpp>
#include <boost/simd/function/simd/lt.hpp>

#endif
