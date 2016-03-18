//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-operator
    Function object implementing ne capabilities

    Returns True if x and y are not equal else False.
    Infix notation can be used with operator '!='.

    This is a convenient alias of @ref is_not_equal
  **/
  const boost::dispatch::functor<tag::ne_> ne = {};
} }
#endif

#include <boost/simd/function/scalar/is_not_equal.hpp>
#include <boost/simd/function/simd/ne.hpp>

#endif
