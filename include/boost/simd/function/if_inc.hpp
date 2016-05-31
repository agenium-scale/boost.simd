//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_INC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_INC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_inc capabilities

    Increments a value by @ref One if a predicate is @ref True.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T1 r = if_inc(cond,y);
    @endcode

    is similar to:

    @code
    T1 r = cond ? t+One<T>() : t  ;
    @endcode

    @par Alias:
    @c if_inc

  **/
  const boost::dispatch::functor<tag::if_inc_> if_inc = {};
} }
#endif

#include <boost/simd/function/scalar/if_inc.hpp>
#include <boost/simd/function/simd/if_inc.hpp>

#endif
