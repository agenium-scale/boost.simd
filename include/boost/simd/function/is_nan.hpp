//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NAN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_nan capabilities

    Returns @ref True or @ref False according x is nan or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_nan(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x != x;
    @endcode

  **/
  const boost::dispatch::functor<tag::is_nan_> is_nan = {};
} }
#endif

#include <boost/simd/function/scalar/is_nan.hpp>
#include <boost/simd/function/simd/is_nan.hpp>

#endif
