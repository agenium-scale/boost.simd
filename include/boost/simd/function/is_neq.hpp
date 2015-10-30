//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NEQ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NEQ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    Returns @ref True if x and y are not equal else @ref False.
    Infix notation can be used with operator '!='.


    This is a convenient alias of @ref is_not_equal
**/
  template<typename T> auto is_neq(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Returns @ref True if x and y are not equal else @ref False.
      Infix notation can be used with operator '!='.


      Function object tied to simd::is_neq

      @see simd::is_neq
    **/
    const boost::dispatch::functor<tag::is_neq_> is_neq = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_neq.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_equal.hpp>
#include <boost/simd/function/simd/is_neq.hpp>

#endif
