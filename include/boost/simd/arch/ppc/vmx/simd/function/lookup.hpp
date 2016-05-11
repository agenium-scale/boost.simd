//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_LOOKUP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_LOOKUP_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD( lookup_
                      , (typename A0)
                      , bs::vmx_
                      , bs::pack_<bd::ints8_<A0>, bs::vmx_>
                      , bs::pack_<bd::ints8_<A0>, bs::vmx_>
                      )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      using u8type = typename A0::template rebind<unsigned char>::template resize<16>;
      return vec_perm(a0.storage(),a0.storage(), bitwise_cast<u8type>(a1).storage());
    }
  };

  BOOST_DISPATCH_OVERLOAD( lookup_
                      , (typename A0)
                      , bs::vmx_
                      , bs::pack_<bd::ints16_<A0>, bs::vmx_>
                      , bs::pack_<bd::ints16_<A0>, bs::vmx_>
                      )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      using u8type = typename A0::template rebind<unsigned char>::template resize<16>;
      using u8n = typename u8type::storage_type;

      // Compute proper permute mask by computing 2*a1/2*a1+1
      u8n v1  = bitwise_cast<u8type>(a1).storage();
      u8n inc = (u8n)(vec_splat_u16(1));
      u8n slt = {1,1,3,3,5,5,7,7,9,9,11,11,13,13,15,15};
      u8n msk = vec_add( inc, vec_sl(vec_perm(v1,v1,slt), vec_splat_u8(1)) );

      return vec_perm(a0.storage(),a0.storage(), msk);
    }
  };

  BOOST_DISPATCH_OVERLOAD( lookup_
                      , (typename A0, typename A1)
                      , bs::vmx_
                      , bs::pack_<bd::type32_<A0>, bs::vmx_>
                      , bs::pack_<bd::ints32_<A1>, bs::vmx_>
                      )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1) const BOOST_NOEXCEPT
    {
      using u8type = typename A1::template rebind<unsigned char>::template resize<16>;
      using u8n = typename u8type::storage_type;

      // Compute proper permute mask by computing 4*a1+0/1/2/3
      u8n v1  = bitwise_cast<u8type>(a1).storage();
      u8n inc = { 0,1,2,3,0,1,2,3, 0, 1, 2, 3, 0, 1, 2, 3 };
      u8n slt = { 3,3,3,3,7,7,7,7,11,11,11,11,15,15,15,15 };
      u8n msk = vec_add( inc, vec_sl( vec_perm(v1, v1, slt), vec_splat_u8(2)) );

      return vec_perm(a0.storage(),a0.storage(), msk);
    }
  };
} } }

#endif
