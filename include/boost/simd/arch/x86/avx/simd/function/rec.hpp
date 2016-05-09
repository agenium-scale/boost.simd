//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/raw.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( rec_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          , bs::raw_tag
                          )
   {
      BOOST_FORCEINLINE A0 operator()(A0 const& a0, raw_tag const&) const BOOST_NOEXCEPT
      {
        return _mm256_rcp_ps( a0 );
      }
   };
} } }

#endif
