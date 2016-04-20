//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/genmask.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( if_else_
                          , (typename A0, typename A1)
                          , bs::avx_
                          , bs::pack_<logical_<A0>, bs::avx_>
                          , bs::pack_<bd::single_<A1>, bs::avx_>
                          , bs::pack_<bd::single_<A1>, bs::avx_>
                          )
   {
     A1 operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
     {
       return _mm256_blendv_ps(a2, a1, bitwise_cast<A1>(genmask(a0)));
     }
   };

   BOOST_DISPATCH_OVERLOAD( if_else_
                          , (typename A0, typename A1)
                          , bs::avx_
                          , bs::pack_<logical_<A0>, bs::avx_>
                          , bs::pack_<bd::double_<A1>, bs::avx_>
                          , bs::pack_<bd::double_<A1>, bs::avx_>
                          )
   {
     A1 operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
     {
       return _mm256_blendv_pd(a2, a1, bitwise_cast<A1>(genmask(a0)));
     }
   };
} } }

#endif
