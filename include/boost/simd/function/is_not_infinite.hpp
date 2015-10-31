//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_INFINITE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_INFINITE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True if x is finite or @ref Nan

    @par Semantic:

    @code
    as_logical_t<T> r = is_not_infinite(x);
    @endcode

    is similar to:

    @code
    if T is floating
      as_logical_t<T> r = (x !=  Inf) && (x != -Inf);
    else
      as_logical_t<T> r = True ;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_not_infinite(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True if x is finite or @ref Nan

      Function object tied to simd::is_not_infinite

      @see simd::is_not_infinite
    **/
    const boost::dispatch::functor<tag::is_not_infinite_> is_not_infinite = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_not_infinite.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_infinite.hpp>
#include <boost/simd/function/simd/is_not_infinite.hpp>

#endif
