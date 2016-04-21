//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOTDEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOTDEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing ifnotdec capabilities

    Decrements a value by @ref One if a predicate is @ref False.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T r = ifnotdec(cond,t);
    @endcode

    is similar to:

    @code
    T r = cond : t : t-One<T>();
    @endcode

  **/
  const boost::dispatch::functor<tag::ifnotdec_> ifnotdec = {};
} }
#endif

#include <boost/simd/function/scalar/ifnotdec.hpp>
#include <boost/simd/function/simd/ifnotdec.hpp>

#endif
