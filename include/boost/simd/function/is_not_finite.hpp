//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_FINITE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_FINITE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True if x is inf, -inf or nan else returns @ref False

    This is a convenient alias of @ref is_invalid
**/
  template<typename T> auto is_not_finite(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True if x is inf, -inf or nan else returns @ref False


      Function object tied to simd::is_not_finite

      @see simd::is_not_finite
    **/
    const boost::dispatch::functor<tag::is_not_finite_> is_not_finite = {};
  }
} }
#endif

#include <boost/simd/function/scalar/is_invalid.hpp>
#include <boost/simd/function/simd/is_not_finite.hpp>

#endif
