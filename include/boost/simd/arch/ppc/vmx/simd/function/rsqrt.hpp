//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_RSQRT_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/refine_rsqrt.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( rsqrt_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< bd::single_<A0>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(const A0& a00) const BOOST_NOEXCEPT
      {
        A0 a0 = refine_rsqrt(a00, raw_(rsqrt)(a00));
        #ifndef BOOST_SIMD_NO_INFINITIES
        a0 = if_zero_else(a00 == Inf<A0>(),a0);
        #endif
        return if_else(is_eqz(a00), Inf<A0>(), a0);
      }
   };

   BOOST_DISPATCH_OVERLOAD( rsqrt_
                          , (typename A0)
                          , bs::vmx_
                          , bs::raw_tag
                          , bs::pack_< bd::single_<A0>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(bs::raw_tag const&, const A0& a0) const BOOST_NOEXCEPT
      {
        return vec_rsqrte( a0.storage() );
      }
   };
} } }

#endif
