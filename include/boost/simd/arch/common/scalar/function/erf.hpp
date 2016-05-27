//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ERF_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ERF_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/simd/arch/common/detail/generic/erf_kernel.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/six.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/exp.hpp>
#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/scalar/negif.hpp>
#include <boost/simd/function/scalar/oneminus.hpp>
#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/simd/function/scalar/sign.hpp>
#include <boost/simd/function/scalar/sqr.hpp>
#include <boost/simd/function/scalar/sqrt.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/scalar/is_nan.hpp>
#endif
#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/scalar/is_inf.hpp>
#include <boost/simd/function/scalar/signnz.hpp>
#endif
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( erf_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::double_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 x) const BOOST_NOEXCEPT
    {
      #ifndef BOOST_SIMD_NO_INVALIDS
      if(is_nan(x)) return x;
      #endif
      A0 y =  bs::abs(x);
      if (y <= Ratio<A0, 15, 32>()) // 0.46875
      {
        return detail::erf_kernel1<A0>::erf1(x, y);
      }
      else if (y <= 4)
      {
        A0 res = detail::erf_kernel1<A0>::erf2(x, y);
        res =    detail::erf_kernel1<A0>::finalize2(res, y);
        res = (Half<A0>() - res) + Half<A0>();
        if (is_ltz(x)) res = -res;
        return res;
      }
      else if  (y <= 26.543)
      {
        A0 res = detail::erf_kernel1<A0>::erf3(x, y);
        res =    detail::erf_kernel1<A0>::finalize2(res, y);
        res = (Half<A0>() - res) + Half<A0>();
        if (is_ltz(x)) res = -res;
        return res;
      }
      else return sign(x);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( erf_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::single_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0) const BOOST_NOEXCEPT
    {
      #ifndef BOOST_SIMD_NO_INVALIDS
      if(is_nan(a0)) return a0;
      #endif
      #ifndef BOOST_SIMD_NO_INFINITIES
      if (bs::is_inf(a0)) return signnz(a0);
      #endif
      A0 x =  bs::abs(a0);
      if (x < Ratio<A0, 2, 3>())
      {
        return a0*detail::erf_kernel<A0>::erf1(sqr(x));
      }
      else
      {
        A0 z = x/oneplus(x)-Ratio<A0, 2, 5>();
        A0 r2 =   oneminus(exp(-sqr(x))*detail::erf_kernel<A0>::erfc2(z));
        if (is_ltz(a0)) r2 = -r2;
        return r2;
      }
   }
  };
  BOOST_DISPATCH_OVERLOAD ( erf_
                          , (typename A0)
                          , bd::cpu_
                          , bs::std_tag
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const std_tag &, A0 a0) const BOOST_NOEXCEPT
    {
      return std::erf(a0);
    }
  };
} } }


#endif
