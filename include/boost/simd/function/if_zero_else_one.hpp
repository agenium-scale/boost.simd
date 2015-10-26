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
#ifndef BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If a0 is true returns zero else returns a1

    @par Semantic:

    For every parameters of types respectively T0:

    @code
    T r = if_zero_else_one(a0);
    @endcode

    is similar to:

    @code
    T r =  a0 ? zero :  one;
    @endcode

    @par Alias:
    @c  if_zero_else_one, @c ifzeroelseone;


    @return a value of the same type as the second parameter

**/
  template<typename T> auto if_zero_else_one(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::if_zero_else_one

      @see simd::if_zero_else_one
    **/
    const boost::dispatch::functor<tag::if_zero_else_one_> if_zero_else_one = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_zero_else_one.hpp>
#include <boost/simd/arch/common/scalar/function/if_zero_else_one.hpp>
//#include <boost/simd/arch/common/function/simd/if_zero_else_one.hpp>

#endif
