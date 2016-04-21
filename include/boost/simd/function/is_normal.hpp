//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NORMAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NORMAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_normal capabilities

    Returns @ref True or @ref False according x is normal or not.

    @par Semantic:

    For x of type T

    @code
    as_logical_t<T> r = is_normal(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = !(is_denormal(x) || is_invalid(x) || is_eqz(a0));
    @endcode

    @see is_invalid, is_denormal, is_eq

  **/
  const boost::dispatch::functor<tag::is_normal_> is_normal = {};
} }
#endif

#include <boost/simd/function/scalar/is_normal.hpp>
#include <boost/simd/function/scalar/is_normal.hpp>
#include <boost/simd/function/simd/is_normal.hpp>

#endif
