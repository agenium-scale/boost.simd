//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_POW_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_POW_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/simd/any.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_flint.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/is_odd.hpp>
#include <boost/simd/function/simd/logical_and.hpp>
#include <boost/simd/function/simd/logical_andnot.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/negif.hpp>
#include <boost/simd/function/simd/pow_abs.hpp>
#include <boost/simd/function/simd/shift_right.hpp>
#include <boost/simd/function/simd/sqr.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD  ( pow_
                           , (typename A0,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::floating_<A0>,X>
                           , bs::pack_<bd::floating_<A0>,X>
                           )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) BOOST_NOEXCEPT
    {
      auto ltza0 = is_ltz(a0);
      A0 z = pow_abs(a0, a1);
      z =  negif(logical_and(is_odd(a1), ltza0), z);
      auto invalid =  logical_andnot(ltza0, is_flint(a1));
      return if_else(invalid, Nan<A0>(), z);
    }
  };

  BOOST_DISPATCH_OVERLOAD(pow_
                          , (typename A0,typename A1,typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          , bs::pack_<bd::uint_<A1>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(const A0& a0, const A1& a1 ) const BOOST_NOEXCEPT
      {
        A0 base = a0;
        A1 exp = a1;
        A0 result = One<A0>();
        while(bs::any(exp))
        {
          result *= if_else(is_odd(exp), base, One<A0>());
          exp >>= 1;
          base = sqr(base);
        }
        return result;
       }
   };

} } }

#endif
