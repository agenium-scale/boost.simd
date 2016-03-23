//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NLT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NLT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_nlt capabilities

    Returns @ref True or @ref False according x is not less or equal to y or is.

    This is a convenient alias of @ref is_not_less
  **/
  const boost::dispatch::functor<tag::is_nlt_> is_nlt = {};
} }
#endif

#include <boost/simd/function/scalar/is_not_less.hpp>
#include <boost/simd/function/simd/is_nlt.hpp>

#endif
