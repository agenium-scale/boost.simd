//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SUBS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SUBS_HPP_INCLUDED

#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/min.hpp>
#include <boost/simd/function/scalar/saturate.hpp>
#include <boost/dispatch/meta/as_signed.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>
#include <boost/dispatch/meta/upgrade.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( subs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0-a1;
    }
  };

  // for int8/int16
  BOOST_DISPATCH_OVERLOAD ( subs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::int_<A0> >
                          , bd::scalar_< bd::int_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      using sz_t = typename brigand::bool_<sizeof(A0) == 4 || sizeof(A0) == 8>::type;
      return impl(a0, a1, sz_t());
    }

    static BOOST_FORCEINLINE A0 impl( A0 a0, A0 a1
                                    , const brigand::false_ &) BOOST_NOEXCEPT
    {
      using u_t = bd::upgrade_t<A0>;
      using s_t = bd::as_signed_t<u_t>;
      return static_cast<A0>(saturate<A0>(s_t(a0)-s_t(a1)));
    }


    static BOOST_FORCEINLINE A0 impl( A0 a0, A0 a1
                                    , const brigand::true_ &) BOOST_NOEXCEPT
    {
      using un_t = bd::as_unsigned_t<A0>;

      un_t ux = a0;
      un_t uy = a1;
      un_t res = ux - uy;

      ux = (ux >> (sizeof(A0)*CHAR_BIT-1)) + Valmax<A0>();

      if(A0((ux ^ uy) & (ux ^ res)) < Zero<A0>()) res = ux;

      return res;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( subs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::uint_<A0> >
                          , bd::scalar_< bd::uint_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      A0 res = a0 - a1;
      res &= -(res <= a0);

      return res;
    }
  };
} } }
#endif

