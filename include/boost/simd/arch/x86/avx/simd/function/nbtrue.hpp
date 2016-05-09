//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/scalar/popcnt.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( nbtrue_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          )
   {
      using result =  bd::scalar_of_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        int r = _mm256_movemask_pd(is_nez(a0));
        return  popcnt(r);
      }
   };

   BOOST_DISPATCH_OVERLOAD( nbtrue_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          )
   {
      using result =  bd::scalar_of_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        int r = _mm256_movemask_ps(is_nez(a0));
        return popcnt(r);
      }
   };

} } }

#endif
