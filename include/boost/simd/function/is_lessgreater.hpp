//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LESSGREATER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LESSGREATER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_lessgreater capabilities

    Returns @ref True if neither x nor y is @ref Nan.

    @par Semantic:

    @code
    as_logical_t<T> r = is_lessgreater(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (x == x) && (y == y);
    @endcode

  **/
  const boost::dispatch::functor<tag::is_lessgreater_> is_lessgreater = {};
} }
#endif

#include <boost/simd/function/scalar/is_lessgreater.hpp>
#include <boost/simd/function/simd/is_lessgreater.hpp>

#endif
