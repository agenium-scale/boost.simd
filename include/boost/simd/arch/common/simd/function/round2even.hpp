//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROUND2EVEN_HPP_INCLUDED

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/plus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(round2even_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::integer_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return a0;
      }
   };

   BOOST_DISPATCH_OVERLOAD(round2even_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        const A0 s   = bitofsign(a0);
        const A0 v   = bitwise_xor(a0, s);
        const A0 t2n = bs::Twotonmb<A0>();
        const A0 d0  = v+t2n;
        const A0 d   = d0-t2n;
        const A0 d1  = if_else(lt(v,t2n),d,v);
        return bitwise_xor(d1, s);
      }
   };
} } }

#endif
