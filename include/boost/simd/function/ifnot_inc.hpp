//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_INC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_INC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing ifnot_inc capabilities

    Increments a value by @ref One if a predicate is @ref False.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T r = ifnot_dec(cond,t);
    @endcode

    is similar to:

    @code
    T r = cond : t : t+one;
    @endcode

  **/
  const boost::dispatch::functor<tag::ifnot_inc_> ifnot_inc = {};
} }
#endif

#include <boost/simd/function/scalar/ifnot_inc.hpp>
#include <boost/simd/function/simd/ifnot_inc.hpp>

#endif
