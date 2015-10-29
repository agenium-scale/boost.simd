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
#ifndef BOOST_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If cond is true returns zero one returns zero

    @par Semantic:

    For every parameter of type COND:

    @code
    auto r = if_one_else_zero(cond);
    @endcode

    is similar to:

    @code
    auto r = cond ? one : zero;
    @endcode

    @par Note:

    The return type is generally COND except in the case where COND is as_logical_t<T>. in which case
    the return type is T.


    @return a value of the type associated to the logical value cond

**/
  template<typename T> auto if_one_else_zero(COND const& cond) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is true returns zero one returns zero


      Function object tied to simd::if_one_else_zero

      @see simd::if_one_else_zero
    **/
    const boost::dispatch::functor<tag::if_one_else_zero_> if_one_else_zero = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_one_else_zero.hpp>
#include <boost/simd/arch/common/scalar/function/if_one_else_zero.hpp>
#include <boost/simd/function/simd/if_one_else_zero.hpp>

#endif
