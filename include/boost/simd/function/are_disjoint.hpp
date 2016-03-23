//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ARE_DISJOINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ARE_DISJOINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing are_disjoint capabilities

    Returns True is only if all bits set in x are not set in y

    This is a convenient alias of @ref is_included_c
  **/
  const boost::dispatch::functor<tag::are_disjoint_> are_disjoint = {};
} }
#endif

#include <boost/simd/function/scalar/is_included_c.hpp>
#include <boost/simd/function/simd/are_disjoint.hpp>

#endif
