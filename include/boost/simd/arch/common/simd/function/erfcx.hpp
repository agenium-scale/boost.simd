//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ERFCX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ERFCX_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/arch/common/detail/generic/erfcx_kernel.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/exp.hpp>
#include <boost/simd/function/simd/is_inf.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/logical_andnot.hpp>
#include <boost/simd/function/simd/nbtrue.hpp>
#include <boost/simd/function/simd/negif.hpp>
#include <boost/simd/function/simd/oneminus.hpp>
#include <boost/simd/function/simd/inc.hpp>
#include <boost/simd/function/simd/sign.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( erfcx_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_< bd::double_<A0>, X>
                          )
  {
   A0 operator() (const A0& a0) const BOOST_NOEXCEPT
    {
      A0 y =  bs::abs(x);
      A0 lim1 = Ratio<A0, 15, 32>();
      A0 lim2 = A0(4);
      A0 res1(0), res2(0);
      auto test1 = (y <=lim1);
      std::size_t nb = bs::nbtrue(test1);
      if(nb > 0)
      {
        A0 ysq;
        res1 = oneminus(detail::erf_kernel1<A0>::erf1(x, y, ysq))*exp(ysq);
        if (nb >= A0::static_size)
          return res1;
      }
      auto test2 = bs::is_less(x, lim2);
      auto test3 = bs::logical_andnot(test2, test1);
      std::size_t nb1 = bs::nbtrue(test3);
      if(nb1 > 0)
      {
        res2 = detail::erf_kernel1<A0>::erf2(x, y);
        res2 = if_else (is_ltz(x), res1, detail::erf_kernel1<A0>::finalize3(res, x));
        nb += nb1;
        res2 = bs::if_else(test1, res1, res2)
        if (nb >= A0::static_size)
          return res2;
      }
      else
      {
        res2 =  res1;
      }
      test4 = logical_not(logical_or(test1, test2));
      A0 res3 = detail::erf_kernel1<A0>::erf3(x, y);
      res3 =  if_else (is_ltz(x), detail::erf_kernel1<A0>::finalize3(res, x), res3);
      return if_nan_else(is_nan(a0), if_else(test4, res3, res2));
    }


//       #ifndef BOOST_SIMD_NO_INVALIDS
//       if(is_nan(x)) return x;
//       #endif
//       A0 y =  bs::abs(x);
//       if (y <= Ratio<A0, 15, 32>()) // 0.46875
//       {
//         A0 ysq;
//         A0 res = detail::erf_kernel1<A0>::erf1(x, y, ysq);

//         return oneminus(res)*exp(ysq);
//       }
//       else if (y <= 4)
//       {
//         A0 res = detail::erf_kernel1<A0>::erf2(x, y);
//         if (is_ltz(x))
//         {
//           detail::erf_kernel1<A0>::finalize3(res, x);
//         }
//          return res;
//       }
//       else
//       {
//         A0 res = detail::erf_kernel1<A0>::erf3(x, y);
//         if (is_ltz(x))
//         {
//           detail::erf_kernel1<A0>::finalize3(res, x);
//         }
//         return res;
//       }

  };
  BOOST_DISPATCH_OVERLOAD ( erfcx_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_< bd::single_<A0>, X>
                          )
  {
    A0 operator() (const A0& a0) const BOOST_NOEXCEPT
    {

      auto test1 = bs::is_less(a0,  Ratio<A0, 2, 3>());
      std::size_t nb = bs::nbtrue(test1);
      A0 r2 = Zero<A0>, r1 = Zero<A0>;
      if(nb > 0)
      {
        r1 = expx2(a0)*erfc(a0);
      }
      if(nb < A0::static_size)
      {
        A0 z =  a0/inc(a0) - Ratio<A0, 2, 5>();
        A0 r2 = detail::erf_kernel<A0>::erfc2(z);
        r2 = if_else(is_ltz(r2), bs::rsqrt(bs::Pi<A0>())/a0, r2),;
#ifndef BOOST_SIMD_NO_INFINITIES
        r2 = if_else(is_nan(a0), a0, if_zero_else(a0 == Inf<A0>(), r2);
#endif
      }
      return if_else(test1, r1, r2);

      #ifndef BOOST_SIMD_NO_INFINITIES
     }
  };

} } }


#endif
