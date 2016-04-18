//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/make_dependent.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>
#include <boost/simd/function/simd/bitwise_or.hpp>
#include <boost/simd/function/simd/bitwise_ornot.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/if_else_allbits.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/simd/split.hpp>
#include <boost/simd/function/simd/splat.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/constant/ratio.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  //TODO as split group available
//   BOOST_DISPATCH_OVERLOAD ( shift_right_
//                           , (typename A0,typename A1 )
//                           , bs::sse2_
//                           , bs::pack_<bd::ints8_<A0>, bs::sse_>
//                           , bd::scalar_<bd::integer_<A1>>
//                          )
//   {
//     using sub_t = detail::make_dependent_t<int16_t,A0>;
//     using gen_t = pack<sub_t, 16>;
//     BOOST_FORCEINLINE A0 operator() ( const A0 & a0
//                                     , const A1 & a1 ) const BOOST_NOEXCEPT
//     {
//       BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_right sse2 int8: a shift is out of range");
//       gen_t a0h, a0l;
//       split(a0, a0l, a0h);
//       return group(shift_right(a0l, a1), shift_right(a0h, a1));

//     }
//   };
  BOOST_DISPATCH_OVERLOAD ( shift_right_
                          , (typename A0,typename A1 )
                          , bs::sse2_
                          , bs::pack_<bd::int16_<A0>, bs::sse_>
                          , bd::scalar_<bd::integer_<A1>>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A1 & a1 ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_right sse2: a shift is out of range");
      return _mm_srai_epi16(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shift_right_
                          , (typename A0,typename A1 )
                          , bs::sse2_
                          , bs::pack_<bd::uint16_<A0>, bs::sse_>
                          , bd::scalar_<bd::integer_<A1>>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A1 & a1 ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_right sse2: a shift is out of range");
      return _mm_srli_epi16(a0, a1);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( shift_right_
                          , (typename A0,typename A1 )
                          , bs::sse2_
                          , bs::pack_<bd::uint32_<A0>, bs::sse_>
                          , bd::scalar_<bd::integer_<A1>>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A1 & a1 ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_right sse2: a shift is out of range");
      return _mm_srli_epi32(a0, int(a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shift_right_
                          , (typename A0,typename A1 )
                          , bs::sse2_
                          , bs::pack_<bd::int32_<A0>, bs::sse_>
                          , bd::scalar_<bd::integer_<A1>>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A1 & a1 ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_right sse2: a shift is out of range");
      return _mm_srai_epi32(a0, int(a1));
    }
  };
  BOOST_DISPATCH_OVERLOAD ( shift_right_
                          , (typename A0,typename A1 )
                          , bs::sse2_
                          , bs::pack_<bd::int64_<A0>, bs::sse_>
                          , bd::scalar_<bd::integer_<A1>>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A1 & a1 ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_right sse2 int64: a shift is out of range");
      A0 that = _mm_srli_epi64(a0, int(a1));
      A0 mask = _mm_srli_epi64(Allbits<A0>(), int(a1));
      return bitwise_ornot(that, if_else_allbits(is_ltz(a0), mask));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shift_right_
                          , (typename A0,typename A1 )
                          , bs::sse2_
                          , bs::pack_<bd::uint8_<A0>, bs::sse_>
                          , bd::scalar_<bd::integer_<A1>>
                         )
  {
    using  int_t = typename detail::make_dependent_t<int16_t,A0>;

    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A1 & a1 ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_right sse2 uint8: a shift is out of range");
      using gen_t = pack<int_t, A0::static_size/2>;
      A0 const Mask1 = bitwise_cast<A0>(gen_t(0x00ff));
      A0 const Mask2 = bitwise_cast<A0>(gen_t(0xff00));

      A0 tmp  = bitwise_and(a0, Mask1);
      A0 tmp1 = _mm_srli_epi16(tmp, int(a1));
      tmp1 = bitwise_and(tmp1, Mask1);
      tmp = bitwise_and(a0, Mask2);
      A0 tmp3 = _mm_srli_epi16(tmp, int(a1));
      return bitwise_or(tmp1, bitwise_and(tmp3, Mask2));
    }
  };
} } }

#endif
