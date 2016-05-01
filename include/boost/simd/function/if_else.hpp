//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    Function object implementing if_else capabilities

    If cond is @ref True returns t else returns f

    @par Semantic:

    For every parameters of types respectively C, T1, T2:

    @code
    T1 r = if_else(cond,t,f);
    @endcode

    is similar to:

    @code
    T1 r = cond ? t : f;
    @endcode

    @par Alias:
    @c where, @c select,  @c sel

    @see  if_else_zero, if_else_allbits, if_zero_else,
    if_allbits_else, if_one_else_zero, if_zero_else_one, bitwise_select
  **/
  const boost::dispatch::functor<tag::if_else_> if_else = {};
} }
#endif

#include <boost/simd/function/scalar/if_else.hpp>
#include <boost/simd/function/simd/if_else.hpp>

#endif
