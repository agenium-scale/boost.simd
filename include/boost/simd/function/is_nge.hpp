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
#ifndef BOOST_SIMD_FUNCTION_IS_NGE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NGE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True if x is not greater or equal to y else returns @ref False.

    This is a convenient alias of @ref is_not_greater_equal
**/
  template<typename T> auto is_nge(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True if x is not greater or equal to y else returns @ref False.


      Function object tied to simd::is_nge

      @see simd::is_nge
    **/
    const boost::dispatch::functor<tag::is_nge_> is_nge = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_nge.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_greater_equal.hpp>
#include <boost/simd/function/simd/is_nge.hpp>

#endif
