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
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_ZERO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If x is true returns t else returns zero

    @par Semantic:

    For every parameters of types respectively COND, T:

    @code
    T r = if_else_zero(cond,t);
    @endcode

    is similar to:

    @code
    T r = cond ? t : zero;
    @endcode

    @return a value of the same type as the second parameter

**/
  template<typename COND, typename T> auto if_else_zero(COND const& cond, T const & t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If x is true returns t else returns zero


      Function object tied to simd::if_else_zero

      @see simd::if_else_zero
    **/
    const boost::dispatch::functor<tag::if_else_zero_> if_else_zero = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_else_zero.hpp>
#include <boost/simd/arch/common/scalar/function/if_else_zero.hpp>
#include <boost/simd/function/simd/if_else_zero.hpp>

#endif
