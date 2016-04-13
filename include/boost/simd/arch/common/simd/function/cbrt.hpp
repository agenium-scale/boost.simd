//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CBRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CBRT_HPP_INCLUDED

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/real_splat.hpp>
#include <boost/simd/constant/third.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_or.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/fast_frexp.hpp>
#include <boost/simd/function/simd/fast_ldexp.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_equal.hpp>
#include <boost/simd/function/simd/is_eqz.hpp>
#include <boost/simd/function/simd/is_gez.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/negate.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/twotomnmbo_3.hpp>
#include <boost/simd/constant/twotonmb.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#endif

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/simd/is_inf.hpp>
#include <boost/simd/function/simd/logical_or.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(cbrt_
                          , (typename A0,typename A1,typename X)
                          , bd::cpu_
                          , bs::pack_<bd::single_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( ) const BOOST_NOEXCEPT
      {
        A0 z =  nt2::abs(a0);
        using int_type =  bs::as_integer_t<A0, signed>;
        using stype =  bd::scalar_of_t<A0>;
  #ifndef BOOST_SIMD_NO_DENORMALS
        auto denormal = is_less(z, Smallestposval<A0>());
        z = if_else(denormal, z*Twotonmb<A0>(), z);
        A0 f = if_else(denormal, Twotomnmbo_3<A0>(), One<A0>());
  #endif
        const A0 CBRT2  = Constant< A0, 0x3fa14518> ();
        const A0 CBRT4  = Constant< A0, 0x3fcb2ff5> ();
        const A0 CBRT2I = Constant< A0, 0x3f4b2ff5> ();
        const A0 CBRT4I = Constant< A0, 0x3f214518> ();
        int_type e;
        A0 x = fast_frexp(z, e);
        x = horn <stype, 0xbe09e49a,
                         0x3f0bf0fe,
                         0xbf745265,
                         0x3f91eb77,
                         0x3ece0609)
                 > (x);
        auto flag = is_gez(e);
        int_type e1 =  nt2::abs(e);
        int_type rem = e1;
        e1 /= Three<int_type>();
        rem -= e1*Three<int_type>();
        e = negate(e1, e);
        const A0 cbrt2 = if_else(flag, CBRT2, CBRT2I);
        const A0 cbrt4 = if_else(flag, CBRT4, CBRT4I);
        A0 fact = if_else(is_equal(rem, One<int_type>()), cbrt2, One<A0>());
        fact = if_else(is_equal(rem, Two<int_type>()), cbrt4, fact);
        x = fast_ldexp(x*fact, e);
        x -= (x-z/sqr(x))*Third<A0>();
  #ifndef BOOST_SIMD_NO_DENORMALS
        x = bitwise_or(x, bitofsign(a0))*f;
  #else
        x = bitwise_or(x, bitofsign(a0));
  #endif
  #ifndef BOOST_SIMD_NO_INFINITIES
        return if_else(logical_or(is_eqz(a0),is_inf(a0)), a0, x);
  #else
        return if_else(is_eqz(a0), a0, x);
  #endif
      }
   };

} }

#endif
