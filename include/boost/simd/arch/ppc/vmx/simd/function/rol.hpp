//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_ROL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_ROL_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/operator/function/details/assert_utils.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/meta/as_unsigned.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( rol_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< bd::integer_<A0>, bs::vmx_>
                          , bs::pack_< bd::integer_<A0>, bs::vmx_>
                          )
   {
     BOOST_FORCEINLINE A0 operator()(A0 const& a0, A0 const& a1) const
      {
        BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "rol : rotation is out of range");
        using c_t =  bd::as_unsigned_t<A0>;
        return vec_rl(a0.storage(), bitwise_cast<c_t>(a1)());
      }
   };

} } }

#endif
