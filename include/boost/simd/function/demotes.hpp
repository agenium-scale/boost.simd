//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEMOTES_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEMOTES_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing demotes capabilities

    take two SIMD vectors of same type and elements of size n
    and return a vector collecting the two in a vector in which
    the elements have size n/2 properly saturated.

    Of course the applicability is conditioned by the existence of compatible
    SIMD vector types

    This is a convenient alias of @ref groups
  **/
  const boost::dispatch::functor<tag::demotes_> demotes = {};
} }
#endif

#include <boost/simd/function/scalar/groups.hpp>
#include <boost/simd/function/simd/demotes.hpp>

#endif
