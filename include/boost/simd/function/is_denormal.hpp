//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_DENORMAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_DENORMAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_denormal capabilities

    Returns @ref True or @ref False according x is denormal or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_denormal(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (x != 0) && (abs(x) < Smallestposval<T>());
    @endcode

    @see Smallestposval

  **/
  const boost::dispatch::functor<tag::is_denormal_> is_denormal = {};
} }
#endif

#include <boost/simd/function/scalar/is_denormal.hpp>
#include <boost/simd/function/scalar/is_denormal.hpp>
#include <boost/simd/function/simd/is_denormal.hpp>

#endif
