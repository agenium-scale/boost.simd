//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_EXPX2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_EXPX2_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/constant/expx2c1.hpp>
#include <boost/simd/constant/expx2c2.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/maxlog.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/exp.hpp>
#include <boost/simd/function/scalar/floor.hpp>
#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/scalar/signnz.hpp>
#include <boost/simd/function/scalar/sqr.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( expx2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
    #ifndef BOOST_SIMD_NO_INFINITIES
      if (is_inf(a0)) return Inf<A0>();
    #endif
      A0 x =  bs::abs(a0);
      /* Represent x as an exact multiple of 1/32 plus a residual.  */
      A0 m = Expx2c1<A0>() * bs::floor(fma(Expx2c2<A0>(), x, Half<A0>()));
      x -= m;
      /* x**2 = m**2 + 2mf + f**2 */
      A0 u = sqr(m);
      A0 u1 = fma(Two<A0>() * m, x, sqr(x));
      if ((u+u1) > bs::Maxlog<A0>()) return Inf<A0>();
      /* u is exact, u1 is small.  */
      return exp(u)*exp(u1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( expx2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_<bd::floating_<A0> >
                          , bd::scalar_<bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 s) const BOOST_NOEXCEPT
    {
      A0 sgn =  signnz(s);
      A0 x =  a0*sgn;
    #ifndef BOOST_SIMD_NO_INFINITIES
      if (bs::is_inf(a0)) return bs::Inf<A0>();
    #endif
      // Represent x as an exact multiple of 1/32 plus a residual.
      A0 m = Expx2c1<A0>()*floor(fma(Expx2c2<A0>(), x, Half<A0>()));
      A0 f =  x-m;
      // x**2 = m**2 + 2mf + f**2
      A0 u = sgn*sqr(m);
      A0 u1 = sgn*fma(m+m,f,sqr(f));
      // u is exact, u1 is small.
      if (u+u1 > Maxlog<A0>()) return bs::Inf<A0>();
      return exp(u)*exp(u1);
    }
  };
} } }


#endif
