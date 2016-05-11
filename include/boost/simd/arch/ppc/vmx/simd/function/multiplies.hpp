//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/detail/dispatch/meta/as_unsigned.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::single_<A0>, bs::vmx_>
                          , bs::pack_<bd::single_<A0>, bs::vmx_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      return vec_madd(a0.storage(),a1.storage(), bs::Mzero<A0>().storage());
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::type16_<A0>, bs::vmx_>
                          , bs::pack_<bd::type16_<A0>, bs::vmx_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      return vec_mladd(a0.storage(),a1.storage(),Zero<A0>().storage());
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::type8_<A0>, bs::vmx_>
                          , bs::pack_<bd::type8_<A0>, bs::vmx_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      auto l = vec_mule(a0.storage(),a1.storage());
      auto r = vec_mulo(a0.storage(),a1.storage());
      return vec_mergel(vec_pack(l,l),vec_pack(r,r));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::uint32_<A0>, bs::vmx_>
                          , bs::pack_<bd::uint32_<A0>, bs::vmx_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      using s_t =  bd::downgrade_t<A0,unsigned>;

      // reinterpret as u16
      s_t short0 = bitwise_cast<s_t>(a0);
      s_t short1 = bitwise_cast<s_t>(a1);

      // shifting constant
      auto shift_ = vec_splat_u32(-16);
      A0 sf = vec_rl(a1.storage(), shift_);

      // Compute high part of the product
      A0 high    = vec_msum ( short0.storage()
                            , bitwise_cast<s_t>(sf).storage()
                            , vec_splat_u32(0)
                            );

      // Complete by adding low part of the 16 bits product
      return vec_add( vec_sl(high.storage(), shift_)
                    , vec_mulo(short0.storage(), short1.storage())
                    );
    }
  };
} } }

#endif
