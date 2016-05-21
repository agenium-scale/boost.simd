//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_REVERSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_REVERSE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( reverse_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      return _mm256_permute_pd( _mm256_permute2f128_pd(a0,a0,1), 5 );
    }
  };

  BOOST_DISPATCH_OVERLOAD ( reverse_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      auto const tmp = _mm256_permute_ps(a0, _MM_SHUFFLE(0,1,2,3) );
      return _mm256_permute2f128_ps(tmp,tmp,1);
    }
  };
} } }

#endif
