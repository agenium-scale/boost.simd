//==================================================================================================
/*!
  @file

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

    If cond is true returns zero else returns one

    @par Semantic:

    For every parameters of type COND:

    @code
    T r = if_zero_else_one(cond);
    @endcode

    is similar to:

    @code
    T r =  cond ? zero :  one;
    @endcode

    @par Note:

    The return type is generally COND except in the case where COND is as_logical_t<T>. in which case
    the return type is T.

    @return a value of the type associated to the logical value cond

**/
  template<typename T> auto if_zero_else_one(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is true returns zero else returns one


      Function object tied to simd::if_zero_else_one

      @see simd::if_zero_else_one
    **/
    const boost::dispatch::functor<tag::if_zero_else_one_> if_zero_else_one = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_zero_else_one.hpp>
#include <boost/simd/arch/common/scalar/function/if_zero_else_one.hpp>
#include <boost/simd/function/simd/if_zero_else_one.hpp>

#endif
