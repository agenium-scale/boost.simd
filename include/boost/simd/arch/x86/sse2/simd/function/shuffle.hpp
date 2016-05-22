//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED

#include <boost/simd/arch/x86/sse2/simd/function/topology.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/slide.hpp>
#include <boost/simd/detail/permutation.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/shuffle.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd  =  boost::dispatch;
  namespace bs  =  boost::simd;
  namespace bsd =  boost::simd::detail;

  // -----------------------------------------------------------------------------------------------
  // Unary SSE 2xtype64 shuffle
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::sse2_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::type64_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == 2
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(bsd::pattern_<Ps...> const&, const A0 & a0) const BOOST_NOEXCEPT
    {
      return do_(a0, typename detail::perform_zeroing<Ps...>::type{});
    }

    // Direct shuffling
    BOOST_FORCEINLINE A0 do_(const A0 & a0, std::false_type const&) const BOOST_NOEXCEPT
    {
      auto v = bitwise_cast<bd::as_floating_t<A0>>(a0);
      return bitwise_cast<A0>( _mm_shuffle_pd(v, v, detail::mask_pd<Ps...>::value) );
    }

    // Masked shuffling
    BOOST_FORCEINLINE A0 do_(const A0 & a0, std::true_type const&) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0>;
      return do_(a0,std::false_type{}) & i_t((detail::zeroing_mask<std::uint64_t,Ps>::value)...);
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Unary SSE 4xint32 shuffle
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::sse2_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == 4
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(bsd::pattern_<Ps...> const&, const A0 & a0) const BOOST_NOEXCEPT
    {
      return do_(a0, typename detail::perform_zeroing<Ps...>::type{});
    }

    // Direct shuffling
    BOOST_FORCEINLINE A0 do_(const A0 & a0, std::false_type const&) const BOOST_NOEXCEPT
    {
      return _mm_shuffle_epi32(a0, detail::mask_ps<Ps...>::value);
    }

    // Masked shuffling
    BOOST_FORCEINLINE A0 do_(const A0 & a0, std::true_type const&) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0>;
      return do_(a0,std::false_type{}) & i_t((detail::zeroing_mask<std::uint32_t,Ps>::value)...);
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Binary SSE 2xtype64 shuffle
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::sse2_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::type64_<A0>, bs::sse_>
                          , bs::pack_<bd::type64_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == 2
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()( bsd::pattern_<Ps...> const&, const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return side(a0, a1,typename detail::which_side<Ps...>::type{});
    }

    // all a0, no a1
    BOOST_FORCEINLINE A0 side(const A0& a0,const A0&, detail::a0_side const&) const BOOST_NOEXCEPT
    {
      return shuffle<Ps...>(a0);
    }

    // all a1, no a0
    BOOST_FORCEINLINE A0 side(const A0&,const A0& a1, detail::a1_side const&) const BOOST_NOEXCEPT
    {
      using card = std::integral_constant<int,sizeof...(Ps)>;
      return shuffle<(Ps!=-1?Ps-card::value:Ps)...>(a1);
    }

    // both a0/a1
    BOOST_FORCEINLINE
    A0 side(const A0& a0,const A0& a1, detail::mixed_side const&) const BOOST_NOEXCEPT
    {
      return do_(a0, a1, typename detail::perform_zeroing<Ps...>::type{});
    }

    // Masked shuffling
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1,std::true_type const&) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0>;
      return do_(a0,a1,std::false_type{}) & i_t((detail::zeroing_mask<std::uint64_t,Ps>::value)...);
    }

    // Regular shuffling checks for topology
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1, std::false_type const&) const BOOST_NOEXCEPT
    {
      return do_(a0,a1, typename detail::sse_topology<2,Ps...>::mode{});
    }

    // Direct shufffling
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1, detail::direct_ const&) const BOOST_NOEXCEPT
    {
      auto const v0 = bitwise_cast<bd::as_floating_t<A0>>(a0);
      auto const v1 = bitwise_cast<bd::as_floating_t<A0>>(a1);
      return bitwise_cast<A0>(_mm_shuffle_pd(v0, v1, detail::mask_pd<Ps...>::value));
    }

    // Indirect shuffling is direct shuffling with a0/a1 permuted
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1, detail::indirect_  const&) const BOOST_NOEXCEPT
    {
      return do_(a1,a0,detail::direct_{});
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Binary SSE 4xint32 shuffle
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::sse2_
                          , bsd::pattern_<Ps...>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == 4
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(bsd::pattern_<Ps...> const&, const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return bitwise_cast<A0>( shuffle<Ps...> ( bitwise_cast<bd::as_floating_t<A0>>(a0)
                                              , bitwise_cast<bd::as_floating_t<A0>>(a1)
                                              )
                              );
    }
  };
} } }

#endif
