//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TANH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TANH_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/arch/common/detail/generic/tanh_kernel.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/exp.hpp>
#include <boost/simd/function/simd/fma.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/nbtrue.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/oneplus.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/simd/function/simd/tanh.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( tanh_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        //////////////////////////////////////////////////////////////////////////////
        // if x = abs(a0) is less than 5/8 tanh is computed using a polynomial(float)
        // (respectively rational(double)) approx from cephes.
        // else
        // tanh(a0) is  sign(a0)*(1 - 2/(exp(2*x)+1))
        //////////////////////////////////////////////////////////////////////////////
        A0 x = bs::abs(a0);
        auto test0= is_less(x, Ratio<A0, 5, 8>());
        A0 bts = bitofsign(a0);
        std::size_t nb = nbtrue(test0);
        A0 z = One<A0>();
        if(nb > 0)
        {
          A0 x2 = sqr(x);
          z = detail::tanh_kernel<A0>::tanh(x, x2);
          if(nb >= A0::static_size) return  bitwise_xor(z, bts);
        }
        A0 r = fma(Mtwo<A0>(), rec(oneplus(exp(x+x))), One<A0>());
        return bitwise_xor(if_else(test0, z, r), bts);
      }
   };

} } }

#endif
