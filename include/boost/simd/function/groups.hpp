//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GROUPS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GROUPS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing groups capabilities

    take two SIMD vectors of same type and elements of size n
    and return a vector collecting the two in a vector in which
    the elements have size n/2 properly saturated.

    Of course the applicability is conditioned by the existence of compatible
    SIMD vector types

    @par Semantic:

    For every parameters of type T0

    @code
    T0 r = groups(x, y);
    @endcode

    is similar to:

    @code
    downgrade<T0> r;
    for(int i=0;i < T0::static_size; ++i)
      r[i] = x[i];
      r[i+T0::static_size] = y[i];
    @endcode

    @par Alias:
    @c demotes, @c narrows

  **/
  const boost::dispatch::functor<tag::groups_> groups = {};
} }
#endif

#include <boost/simd/function/scalar/groups.hpp>
#include <boost/simd/function/simd/groups.hpp>

#endif
