//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing seldec capabilities

    Decrements a value by @ref One if a predicate is @ref True.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T r = seldec(cond,t);
    @endcode

    is similar to:

    @code
    T r = cond : t-One<T>() : t;
    @endcode

    @par Alias:
    @c if_dec

  **/
  const boost::dispatch::functor<tag::seldec_> seldec = {};
} }
#endif

#include <boost/simd/function/scalar/seldec.hpp>
#include <boost/simd/function/simd/seldec.hpp>

#endif
