//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SHUFFLE_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  // -----------------------------------------------------------------------------------------------
  // Yes, yes, we're shuffling scalar values. What do we do for the sake of genericity
  // -----------------------------------------------------------------------------------------------

  // -----------------------------------------------------------------------------------------------
  // Handle invalid Indexes by a flat static_assert
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int Idx, typename A0)
                          , bd::cpu_
                          , bs::detail::pattern_<Idx>
                          , bd::scalar_< bd::unspecified_<A0> >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<Idx> const&, A0 const& a0) const BOOST_NOEXCEPT
    {
      static_assert ( Idx >= -1 && Idx < 1
                    , "boost::simd::shuffle: Invalid permutation index"
                    );
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int Idx, typename A0)
                          , bd::cpu_
                          , bs::detail::pattern_<Idx>
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::scalar_< bd::unspecified_<A0> >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<Idx> const&, A0 const& a0, A0 const&) const BOOST_NOEXCEPT
    {
      static_assert ( Idx >= -1 && Idx < 2
                    , "boost::simd::shuffle: Invalid permutation index"
                    );
      return a0;
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Two cases of unary shuffle for scalar : 0, -1
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0)
                          , bd::cpu_
                          , bs::detail::pattern_<0>
                          , bd::scalar_< bd::unspecified_<A0> >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<0> const&, A0 const& a0) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0)
                          , bd::cpu_
                          , bs::detail::pattern_<-1>
                          , bd::scalar_< bd::unspecified_<A0> >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<-1> const&, A0 const&) const BOOST_NOEXCEPT
    {
      return A0{0};
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Three cases of unary shuffle for scalar : 0, 1, -1
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0)
                          , bd::cpu_
                          , bs::detail::pattern_<0>
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::scalar_< bd::unspecified_<A0> >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<0> const&, A0 const& a0, A0 const&) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0)
                          , bd::cpu_
                          , bs::detail::pattern_<1>
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::scalar_< bd::unspecified_<A0> >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<1> const&, A0 const&, A0 const& a1) const BOOST_NOEXCEPT
    {
      return a1;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename A0)
                          , bd::cpu_
                          , bs::detail::pattern_<-1>
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::scalar_< bd::unspecified_<A0> >
                          )
  {
    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<-1> const&, A0 const&, A0 const&) const BOOST_NOEXCEPT
    {
      return A0{0};
    }
  };
} } }

#endif
