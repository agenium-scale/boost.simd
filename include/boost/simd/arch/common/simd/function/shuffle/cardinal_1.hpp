//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_CARDINAL_1_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_CARDINAL_1_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  // -----------------------------------------------------------------------------------------------
  // Yes, yes, we're shuffling for pack of cardinal 1 ... Jeez, TMP eats my soul
  // -----------------------------------------------------------------------------------------------

  // -----------------------------------------------------------------------------------------------
  // Two cases of unary shuffle for scalar : 0, -1
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0, typename X)
                          , bs::simd_
                          , bs::detail::pattern_<0>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<0> const&, A0 const& a0) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0, typename X)
                          , bs::simd_
                          , bs::detail::pattern_<-1>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<-1> const&, A0 const&) const BOOST_NOEXCEPT
    {
      return Zero<A0>();
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Three cases of unary shuffle for scalar : 0, 1, -1
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0, typename X)
                          , bs::simd_
                          , bs::detail::pattern_<0>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<0> const&, A0 const& a0, A0 const&) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0, typename X)
                          , bs::simd_
                          , bs::detail::pattern_<1>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<1> const&, A0 const&, A0 const& a1) const BOOST_NOEXCEPT
    {
      return a1;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0, typename X)
                          , bs::simd_
                          , bs::detail::pattern_<-1>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<-1> const&, A0 const&, A0 const&) const BOOST_NOEXCEPT
    {
      return Zero<A0>();
    }
  };
} } }

#endif
