//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATANH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATANH_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/fma.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/log1p.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/oneminus.hpp>
#include <boost/simd/function/simd/plus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( atanh_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        A0 absa0 = bs::abs(a0);
        A0 t =  absa0+absa0;
        A0 z1 = oneminus(absa0);
        auto test =  is_less(absa0, Half<A0>());
        A0 tmp = if_else(test, absa0, t)/z1;
        return bitwise_xor(bitofsign(a0), Half<A0>()*log1p(if_else(test, fma(t,tmp,t), tmp)));
      }
   };

} } }

#endif
