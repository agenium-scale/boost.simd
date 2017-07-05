//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_MINUS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/slice.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( minus_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return _mm256_sub_pd(a0,a1);
      }
   };

   BOOST_DISPATCH_OVERLOAD( minus_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return _mm256_sub_ps(a0,a1);
      }
   };
   BOOST_DISPATCH_OVERLOAD( minus_
                          , (typename A0)
                          , bs::avx_
                          , bs::saturated_tag
                          , bs::pack_< bd::uint_<A0>, bs::avx_>
                          , bs::pack_< bd::uint_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const saturated_tag &, A0 const& a0, A0 const& a1) const
      {
        auto l0 = slice_low(a0);
        auto l1 = slice_low(a1);
        auto h0 = slice_high(a0);
        auto h1 = slice_high(a1);

        return combine( bs::saturated_(bs::minus)(l0,l1), bs::saturated_(bs::minus)(h0,h1) );
      }
   };

   BOOST_DISPATCH_OVERLOAD( minus_
                          , (typename A0)
                          , bs::avx_
                          , bs::saturated_tag
                          , bs::pack_< bd::int_<A0>, bs::avx_>
                          , bs::pack_< bd::int_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const saturated_tag &, A0 const& a0, A0 const& a1) const
      {
        auto l0 = slice_low(a0);
        auto l1 = slice_low(a1);
        auto h0 = slice_high(a0);
        auto h1 = slice_high(a1);

        return combine( bs::saturated_(bs::minus)(l0,l1), bs::saturated_(bs::minus)(h0,h1) );
      }
   };
} } }

#endif
