//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_INCLUDED_C_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_INCLUDED_C_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
 /*!
    @ingroup group-reduction
    Function object implementing is_included_c capabilities

    Returns @ref True is only if all bits set in x are not set in y

    @par Semantic:

    For every parameters of types respectively T0, T1 of same bit size:

    @code
    bool r = is_included_c(x,y);
    @endcode

    is similar to:

    @code
    bool r = all(x&y == zero);
    @endcode
  **/
  const boost::dispatch::functor<tag::is_included_c_> is_included_c = {};
} }
#endif

#include <boost/simd/function/scalar/is_included_c.hpp>
#include <boost/simd/function/simd/is_included_c.hpp>

#endif
