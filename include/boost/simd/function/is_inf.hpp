//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_INF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_INF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_inf capabilities

    Returns @ref True if x is inf or -inf else returns @ref False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_inf(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (x == Inf) || (x == -Inf);
    @endcode

  **/
  const boost::dispatch::functor<tag::is_inf_> is_inf = {};
} }
#endif

#include <boost/simd/function/scalar/is_inf.hpp>
#include <boost/simd/function/simd/is_inf.hpp>

#endif
