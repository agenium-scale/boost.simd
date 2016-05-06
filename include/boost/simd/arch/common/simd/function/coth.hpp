//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COTH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COTH_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/hyperbolic/function/details/tanh_kernel.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/constant/fiveo_8.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/coth.hpp>
#include <boost/simd/function/simd/exp.hpp>
#include <boost/simd/function/simd/fma.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/inbtrue.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/minusone.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/function/simd/sqr.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( coth_
                          , (typename A0, typename X)
                          , bs::cpu_
                          , bs::pack_< bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        //////////////////////////////////////////////////////////////////////////////
        // if x = abs(a0) is less than 5/8 sinh is computed using a polynomial(float)
        // (respectively rational(double)) approx inspirated from cephes.
        // else
        // coth(a0) is  sign(a0)*(1 + 2/(exp(2*x)-1))
        //////////////////////////////////////////////////////////////////////////////
        using bA0 =  bs::as_logical_t<A0>;
        A0 x = bs::abs(a0);
        bA0 test0= lt(x, Fiveo_8<A0>());
        A0 bts = bitofsign(a0);
        std::size_t nb = inbtrue(test0);
        A0 z = One<A0>();
        if(nb> 0)
        {
          z = detail::tanh_kernel<A0>::coth(x, sqr(x));
          if(nb >= meta::cardinal_of<A0>::value) return  b_xor(z, bts);
        }
        A0 r = fma(Two<A0>(), rec(minusone(exp(x+x))), One<A0>());
        return b_xor(if_else(test0, z, r), bts);
      }
   };

} } }

#endif
