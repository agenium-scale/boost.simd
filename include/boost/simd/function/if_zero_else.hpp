//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_zero_else capabilities

    If cond is @ref True returns @ref Zero else returns f

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T r = if_zero_else(cond,f);
    @endcode

    is similar to:

    @code
    T r = cond ? Zero<T>() : f;
    @endcode

  **/
  const boost::dispatch::functor<tag::if_zero_else_> if_zero_else = {};
} }
#endif

#include <boost/simd/function/scalar/if_zero_else.hpp>
#include <boost/simd/function/simd/if_zero_else.hpp>

#endif
