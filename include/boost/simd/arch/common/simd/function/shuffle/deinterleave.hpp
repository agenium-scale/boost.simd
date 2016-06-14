//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_DEINTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_DEINTERLEAVE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/arch/common/simd/function/shuffle/pattern/deinterleave.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/deinterleave_second.hpp>

namespace boost { namespace simd { namespace ext
{
  // -----------------------------------------------------------------------------------------------
  // deinterleave_*
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename Ps, int Base, int Fwd, int Bwd, typename A0, typename X)
                          , bd::cpu_
                          , bs::deinterleave_pattern<Base,Fwd,Bwd,Ps>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    static_assert ( Ps::static_size == std::size_t(A0::static_size)
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE A0 operator()(Ps const&, A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return side(a0,a1,std::integral_constant<int,Base>{});
    }

    // Select deinterleave_first as operation
    BOOST_FORCEINLINE static
    A0 side(A0 const& a0, A0 const& a1, std::integral_constant<int,1> const&) BOOST_NOEXCEPT
    {
      return do_( deinterleave_first, a0, a1
                , std::integral_constant<int,Fwd>{},std::integral_constant<int,Bwd>{}
                );
    }

    // Select deinterleave_second as operation
    BOOST_FORCEINLINE static
    A0 side(A0 const& a0, A0 const& a1, std::integral_constant<int,2> const&) BOOST_NOEXCEPT
    {
      return do_( deinterleave_second, a0, a1
                , std::integral_constant<int,Fwd>{},std::integral_constant<int,Bwd>{}
                );
    }

    using nope = std::integral_constant<int,0x00>;
    using regular = std::integral_constant<int,0x01>;
    using forward = std::integral_constant<int,0x02>;
    using backward = std::integral_constant<int,0x04>;

    // forward, no zero
    template<typename F>
    static BOOST_FORCEINLINE A0 do_ ( F const& f, A0 const& a0, A0 const& a1
                                    , regular const&, nope const&
                                    ) BOOST_NOEXCEPT
    {
      return f(a0,a1);
    }

    // forward, zero first
    template<typename F>
    static BOOST_FORCEINLINE A0 do_ ( F const& f, A0 const&, A0 const& a1
                                    , forward const&, nope const&
                                    ) BOOST_NOEXCEPT
    {
      return f(Zero<A0>(),a1);
    }

    // forward, zero last
    template<typename F>
    static BOOST_FORCEINLINE A0 do_ ( F const& f, A0 const& a0, A0 const&
                                    , backward const&, nope const&
                                    ) BOOST_NOEXCEPT
    {
      return f(a0,Zero<A0>());
    }

    // backward, no zero
    template<typename F>
    static BOOST_FORCEINLINE A0 do_ ( F const& f, A0 const& a0, A0 const& a1
                                    , nope const&, regular const&
                                    ) BOOST_NOEXCEPT
    {
      return f(a1,a0);
    }

    // backward, zero first
    template<typename F>
    static BOOST_FORCEINLINE A0 do_ ( F const& f, A0 const& a0, A0 const&
                                    , nope const&, backward const&
                                    ) BOOST_NOEXCEPT
    {
      return f(Zero<A0>(),a0);
    }

    // backward, zero last
    template<typename F>
    static BOOST_FORCEINLINE A0 do_ ( F const& f, A0 const&, A0 const& a1
                                    , nope const&, forward const&
                                    ) BOOST_NOEXCEPT
    {
      return f(a1,Zero<A0>());
    }
  };
} } }

#endif
