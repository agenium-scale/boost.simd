//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing is_nge capabilities

    Returns @ref True if x is not greater or equal to y else returns @ref False.

    This is a convenient alias of @ref is_not_greater_equal
  **/
  const boost::dispatch::functor<tag::is_nge_> is_nge = {};
} }
#endif

#include <boost/simd/function/scalar/is_not_greater_equal.hpp>
#include <boost/simd/function/simd/is_nge.hpp>

#endif
