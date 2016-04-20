//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/popcnt.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( inbtrue_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE std::size_t operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return  bs::popcnt(_mm256_movemask_pd(is_nez(a0)));
      }
   };

   BOOST_DISPATCH_OVERLOAD( inbtrue_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE std::size_t operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return  bs::popcnt(_mm256_movemask_ps(is_nez(a0)));
      }
   };

} } }

#endif
