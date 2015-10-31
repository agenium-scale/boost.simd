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
#ifndef BOOST_SIMD_FUNCTION_IS_FINITE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_FINITE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True if x is not inf, -inf or nan, else returns @ref False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_finite(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x-x ==  0;
    @endcode

    @par Alias:
    is_not_invalid

    @return a logical value

**/
  template<typename T> auto is_finite(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True if x is not inf, -inf or nan, else returns @ref False.


      Function object tied to simd::is_finite

      @see simd::is_finite
    **/
    const boost::dispatch::functor<tag::is_finite_> is_finite = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_finite.hpp>
#include <boost/simd/arch/common/scalar/function/is_finite.hpp>
#include <boost/simd/function/simd/is_finite.hpp>

#endif
