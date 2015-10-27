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
#ifndef BOOST_SIMD_FUNCTION_GROUPS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GROUPS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    take two SIMD vectors of same type and elements of size n
    and return a vector collecting the two in a vector in which
    the elements have size n/2 properly saturated.

    Of course the applicability is conditioned by the existence of compatible
    SIMD vector types

    @par Semantic:

    For every parameters of type T0

    @code
    T0 r = groups(a0, a1);
    @endcode

    is similar to:

    @code
    downgrade<T0> r;
    for(int i=0;i < T0::static_size; ++i)
      r[i] = a0[i];
      r[i+T0::static_size] = a1[i];
    @endcode

    @par Alias:
    @c demotes, @c narrows


    @return a value of the same type as the second parameter

**/
  template<typename T> auto groups(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::groups

      @see simd::groups
    **/
    const boost::dispatch::functor<tag::groups_> groups = {};
  }
} }
#endif

#include <boost/simd/function/definition/groups.hpp>
#include <boost/simd/arch/common/scalar/function/groups.hpp>
//#include <boost/simd/arch/common/function/simd/groups.hpp>

#endif
