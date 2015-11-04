//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_CBRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_CBRT_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#endif
#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/twotomnmbo_3.hpp>
#include <boost/simd/constant/twotonmb.hpp>
#endif
#include <boost/simd/arch/common/detail/generic/horner.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/third.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/bitofsign.hpp>
#include <boost/simd/function/scalar/bitwise_or.hpp>
#include <boost/simd/function/scalar/frexp.hpp>
#include <boost/simd/function/scalar/is_gez.hpp>
#include <boost/simd/function/scalar/ldexp.hpp>
#include <boost/simd/function/scalar/negate.hpp>
#include <boost/simd/function/scalar/sqr.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( cbrt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::double_<A0> >
                          )
  {


    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 z =  bs::abs(a0);
    #ifndef BOOST_SIMD_NO_INFINITIES
      if (z == bs::Inf<A0>() || (z == 0)) return a0;
    #else
      if (z == 0) return a0;
    #endif
    #ifndef BOOST_SIMD_NO_DENORMALS
      A0 f = One<A0>();
      if (z < Smallestposval<A0>())
      {
        z *= Twotonmb<A0>();
        f  = Twotomnmbo_3<A0>();
      }
    #endif
      const A0 CBRT2  = Constant< A0, 0x3ff428a2f98d728bll> ();
      const A0 CBRT4  = Constant< A0, 0x3ff965fea53d6e3dll> ();
      const A0 CBRT2I = Constant< A0, 0x3fe965fea53d6e3dll> ();
      const A0 CBRT4I = Constant< A0, 0x3fe428a2f98d728bll> ();
      using i_t = bd::as_integer_t<A0, signed>;
      i_t e;
      A0 x = frexp(z, e, fast_);
      x = horner < BOOST_SIMD_HORNER_COEFF_T(A0, 5,
                                             (0xbfc13c93386fdff6ll,
                                              0x3fe17e1fc7e59d58ll,
                                              0xbfee8a4ca3ba37b8ll,
                                              0x3ff23d6ee505873all,
                                              0x3fd9c0c12122a4fell)
                                            ) > (x);
      const bool flag = is_gez(e);
      i_t e1 =  bs::abs(e);
      i_t rem = e1;
      e1 /= Three<i_t>();
      rem -= e1*Three<i_t>();
      e =  negate(e1, e);
      const A0 cbrt2 = flag ? CBRT2 : CBRT2I;
      const A0 cbrt4 = flag ? CBRT4 : CBRT4I;
      A0 fact = (rem == One<i_t>()) ? cbrt2: One<A0>();
      fact = (rem == Two<i_t>() ? cbrt4 : fact);
      x = ldexp(x*fact, e, fast_);
      x -= (x-z/sqr(x))*Third<A0>();
      x -= (x-z/sqr(x))*Third<A0>(); //two newton passes
    #ifndef BOOST_SIMD_NO_DENORMALS
      return bitwise_or(x, bitofsign(a0))*f;
    #else
      return bitwise_or(x, bitofsign(a0));
    #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cbrt_
                          , (typename A0)
                             , bd::cpu_
                            , bd::scalar_< bd::single_<A0> >
                            )
  {
    A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 z =  bs::abs(a0);
    #ifndef BOOST_SIMD_NO_INFINITIES
      if (z == bs::Inf<A0>() || (z == 0)) return a0;
    #else
      if  (z == 0) return a0;
    #endif
    #ifndef BOOST_SIMD_NO_DENORMALS
      A0 f = One<A0>();
      if (z < Smallestposval<A0>())
      {
        z *= Twotonmb<A0>();
        f = Twotomnmbo_3<A0>();
      }
    #endif
      const A0 CBRT2  = Constant< A0, 0x3fa14518> ();
      const A0 CBRT4  = Constant< A0, 0x3fcb2ff5> ();
      const A0 CBRT2I = Constant< A0, 0x3f4b2ff5> ();
      const A0 CBRT4I = Constant< A0, 0x3f214518> ();
      using i_t = bd::as_integer_t<A0, signed>;
      i_t e;
      A0 x = frexp(z, e, fast_);
      x = horner < BOOST_SIMD_HORNER_COEFF_T(A0, 5,
                                             (0xbe09e49a,
                                              0x3f0bf0fe,
                                              0xbf745265,
                                              0x3f91eb77,
                                              0x3ece0609)
                                            ) > (x);
      const bool flag = is_gez(e);
      i_t e1 =  bs::abs(e);
      i_t rem = e1;
      e1 /= Three<i_t>();
      rem -= e1*Three<i_t>();
      e =  negate(e1, e);

      const A0 cbrt2 = flag ? CBRT2 : CBRT2I;
      const A0 cbrt4 = flag ? CBRT4 : CBRT4I;
      A0 fact = (rem ==  One<i_t>()) ? cbrt2 : One<A0>();
      fact = (rem == Two<i_t>()) ? cbrt4 : fact;
      x = ldexp(x*fact, e, fast_);
      x -= (x-z/sqr(x))*Third<A0>();
    #ifndef BOOST_SIMD_NO_DENORMALS
      return bitwise_or(x, bitofsign(a0))*f;
    #else
      return bitwise_or(x, bitofsign(a0));
    #endif
    }
  };
} } }

#endif
