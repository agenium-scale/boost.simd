//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NTHROOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NTHROOT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/pack.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_or.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/if_nan_else.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/if_else_zero.hpp>
#include <boost/simd/function/simd/if_zero_else.hpp>
#include <boost/simd/function/simd/is_equal.hpp>
#include <boost/simd/function/simd/is_eqz.hpp>
#include <boost/simd/function/simd/is_even.hpp>
#include <boost/simd/function/simd/is_inf.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/logical_and.hpp>
#include <boost/simd/function/simd/logical_andnot.hpp>
#include <boost/simd/function/simd/logical_or.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/minusone.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/pow.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/function/simd/if_plus.hpp>
#include <boost/simd/function/simd/tofloat.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( nthroot_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::integer_<A1>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
      using bA0 = bs::as_logical_t<A0>;
      A0 x =  bs::abs(a0);
      A0 aa1 = bs::tofloat(a1);
      A0 y = bs::pow(x,rec(aa1));
      bA0 nul_a1 =  bitwise_cast<bA0>(bs::is_eqz(a1));
      bA0 is_ltza0 = is_ltz(a0);
      bA0 is_odda1 = bitwise_cast<bA0>(is_odd(a1));
      A0 a11 = bs::tofloat(a1-bs::if_else_zero(nul_a1, Mone<A1>()));
      y = bs::if_plus( bs::logical_or(bs::is_nez(y), nul_a1)
                     , y
                     , -(bs::pow(y, aa1) - x)/(aa1* bs::pow(y, bs::minusone(a11)))
                     );
      // Correct numerical errors (since, e.g., 64^(1/3) is not exactly 4)
      // by one iteration of Newton's method
      bA0 test =  logical_andnot(is_ltza0, is_odda1);
      bA0 done =  test;
      y = if_nan_else(test, y);  // a0 < O and a1 is not odd
      bA0 newtest =  is_equal(x, One<A0>());
      test  = logical_andnot(newtest, done);
      done  = logical_or(done, newtest);
      y = if_else(test, a0, y); // 1^a1 or (-1)^a1
      newtest =  nul_a1;
      test  = logical_andnot(newtest, done);
      done  = logical_or(done, newtest);
      y =  if_else(test,
                   if_zero_else(is_less(x, One<A0>()),
                                sign(a0)*Inf<A0>()
                               ),
                   y);
      newtest =  is_eqz(a0);
      test  = logical_andnot(newtest, done);
      done  = logical_or(done, newtest);
      y =  if_zero_else(test, y);
      #ifndef BOOST_SIMD_NO_INFINITIES
      newtest =  is_inf(a0);
      test  = logical_andnot(newtest, done);
      done  = logical_or(done, newtest);
      y =  if_else(test, if_else(is_nez(a1), a0, One<A0>()), y);
      #endif
      return bs::bitwise_or(y, bs::bitofsign(a0));
      }
   };

} } }

#endif
