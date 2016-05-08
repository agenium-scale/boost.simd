//==================================================================================================
/**
  Copyright 2016 Numscale SAS
  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( interleave_first_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      // 0x20 is SCR1[0:127]|SRC2[0:127] according to Intel AVX manual
      // The result of unpack_*_pd puts parts in the proper pairs beforehand
      return _mm256_permute2f128_pd ( _mm256_unpacklo_pd(a0,a1)
                                    , _mm256_unpackhi_pd(a0,a1)
                                    , 0x20
                                    );
    }
  };

  BOOST_DISPATCH_OVERLOAD ( interleave_first_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      // 0x20 is SCR1[0:127]|SRC2[0:127] according to Intel AVX manual
      // The result of unpack_*_ps puts parts in the proper pairs beforehand
      return _mm256_permute2f128_ps ( _mm256_unpacklo_ps(a0,a1)
                                    , _mm256_unpackhi_ps(a0,a1)
                                    , 0x20
                                    );
    }
  };
} } }

#endif
