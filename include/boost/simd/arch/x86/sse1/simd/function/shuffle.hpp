//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED

#include <boost/simd/arch/x86/sse1/simd/function/topology.hpp>
#include <boost/simd/detail/permutation.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/shuffle.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  // -----------------------------------------------------------------------------------------------
  // 4xType32 shuffle optimized patterns
  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0), bs::sse1_
                          , bsd::pattern_<0, 1, 4, 5>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          )
  BOOST_SIMD_GENERIC_BINARY_PATTERN ( ( bitwise_cast<A0>( bd::as_floating_t<A0>
                                                          ( _mm_movelh_ps
                                                            ( bitwise_cast<bd::as_floating_t<A0>>(a0)
                                                            , bitwise_cast<bd::as_floating_t<A0>>(a1)
                                                            )
                                                          )
                                                        )
                                      )
                                    , 0, 1, 4, 5
                                    );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0), bs::sse1_
                          , bsd::pattern_<2, 3, 6, 7>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          )
  BOOST_SIMD_GENERIC_BINARY_PATTERN ( ( bitwise_cast<A0>( bd::as_floating_t<A0>
                                                          ( _mm_movehl_ps
                                                            ( bitwise_cast<bd::as_floating_t<A0>>(a1)
                                                            , bitwise_cast<bd::as_floating_t<A0>>(a0)
                                                            )
                                                          )
                                                        )
                                      )
                                    , 2, 3, 6, 7
                                    );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0), bs::sse1_
                          , bsd::pattern_<4, 5, 0, 1>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          )
  BOOST_SIMD_GENERIC_BINARY_PATTERN( (shuffle<0,1,4,5>(a1,a0)), 4, 5, 0, 1 );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0), bs::sse1_
                          , bsd::pattern_<6, 7, 2, 3>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          )
  BOOST_SIMD_GENERIC_BINARY_PATTERN( (shuffle<2,3,6,7>(a1,a0)), 6, 7, 2, 3 );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0), bs::sse1_
                          , bsd::pattern_<0, 1,-1,-1>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          )
  BOOST_SIMD_GENERIC_PATTERN( (shuffle<0,1,4,5>(a0,Zero<A0>())), 0, 1,-1,-1 );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0), bs::sse1_
                          , bsd::pattern_<-1,-1, 2, 3>
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          )
  BOOST_SIMD_GENERIC_PATTERN( (shuffle<2,3,6,7>(Zero<A0>(),a0)), -1,-1, 2, 3 );

  // -----------------------------------------------------------------------------------------------
  // Unary SSE 4xfloat shuffle
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::sse1_
                          , bs::detail::pattern_<Ps...>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == 4
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(bs::detail::pattern_<Ps...> const&, const A0 & a0) const BOOST_NOEXCEPT
    {
      return do_(a0, typename detail::perform_zeroing<Ps...>::type{});
    }

    // Direct shuffling
    BOOST_FORCEINLINE A0 do_(const A0 & a0, std::false_type const&) const BOOST_NOEXCEPT
    {
      return _mm_shuffle_ps(a0,a0, detail::mask_ps<Ps...>::value);
    }

    // Masked shuffling
    BOOST_FORCEINLINE A0 do_(const A0 & a0, std::true_type const&) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0>;
      return do_(a0,std::false_type{}) & i_t((detail::zeroing_mask<std::uint32_t,Ps>::value)...);
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Binary SSE 4xfloat shuffle
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int... Ps, typename A0)
                          , bs::sse1_
                          , bs::detail::pattern_<Ps...>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    static_assert ( sizeof...(Ps) == 4
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator() ( bs::detail::pattern_<Ps...> const&
                  , const A0 & a0, const A0 & a1
                  ) const BOOST_NOEXCEPT
    {puts("SSE1 POWWA");
      return do_(a0, a1, typename detail::perform_zeroing<Ps...>::type{});
    }

    // Masked shuffling
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1,std::true_type const&) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0>;
      return do_(a0,a1,std::false_type{}) & i_t((detail::zeroing_mask<std::uint32_t,Ps>::value)...);
    }

    // Regular shuffling checks for topology
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1, std::false_type const&) const BOOST_NOEXCEPT
    {
      return do_(a0,a1, typename detail::sse_topology<4,Ps...>::mode{});
    }

    // Direct shufffling
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1, detail::direct_ const&) const BOOST_NOEXCEPT
    {
      return _mm_shuffle_ps(a0, a1, detail::mask_ps<Ps...>::value);
    }

    // Indirect shuffling is direct shuffling with a0/a1 permuted
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1, detail::indirect_  const&) const BOOST_NOEXCEPT
    {
      return _mm_shuffle_ps(a1, a0, detail::mask_ps<Ps...>::value);
    }

    // Other cases just fill in by hand
    BOOST_FORCEINLINE
    A0 do_(const A0 & a0, const A0 & a1, detail::mixed_ const&) const BOOST_NOEXCEPT
    {
      return A0{ (Ps<4  ? bs::extract<Ps>(a0) : bs::extract<Ps-4>(a1))... };
    }
  };
} } }

#endif
