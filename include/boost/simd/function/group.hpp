//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GROUP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GROUP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    SIMD register type-based group

    take two Pack vectors of same type and elements of size n
    and return a vector collecting the two in a vector in which
    the elements have size n/2. Of course the function is not defined
    for n == 1.

    @par Semantic:

    For every parameters of type T

    @code
    downgrade_t<T> r = group(x, y);
    @endcode

    is similar to:

    @code
    downgrade<T0> r;
    for(int i=0;i < T0::static_size; ++i)
      r[i] = x[i];
      r[i+T0::static_size] = y[i];
    @endcode

    @par Alias:
    @c demote, @c narrow

**/
  template<typename T> auto group(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      Function object tied to simd::group

      @see simd::group
    **/
    const boost::dispatch::functor<tag::group_> group = {};
  }
} }
#endif

#include <boost/simd/function/definition/group.hpp>
#include <boost/simd/arch/common/scalar/function/group.hpp>
#include <boost/simd/function/simd/group.hpp>

#endif
