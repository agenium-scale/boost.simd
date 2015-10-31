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
#ifndef BOOST_SIMD_FUNCTION_IS_EQ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_EQ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    Returns @ref True or @ref False
    according x and y are equal or not. Infix notation can be used with operator '=='

    This is a convenient alias of @ref is_equal
**/
  template<typename T> auto is_eq(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Returns @ref True or @ref False
      according x and y are equal or not. Infix notation can be used with operator '=='


      Function object tied to simd::is_eq

      @see simd::is_eq
    **/
    const boost::dispatch::functor<tag::is_eq_> is_eq = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_eq.hpp>
#include <boost/simd/arch/common/scalar/function/is_equal.hpp>
#include <boost/simd/function/simd/is_eq.hpp>

#endif
