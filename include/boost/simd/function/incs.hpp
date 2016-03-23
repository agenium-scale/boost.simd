//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INCS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INCS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing incs capabilities

    Returns the entry plus one, saturated in the entry type.

    This is a convenient alias of @ref abs
  **/
  const boost::dispatch::functor<tag::incs_> incs = {};
} }
#endif

#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/simd/function/simd/incs.hpp>

#endif
