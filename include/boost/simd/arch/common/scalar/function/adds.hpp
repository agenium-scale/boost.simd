//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ADDS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ADDS_HPP_INCLUDED

#include <boost/dispatch/hierarchy.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <type_traits>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/saturate.hpp>
#include <boost/simd/function/scalar/min.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>
#include <boost/dispatch/meta/upgrade.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
 BOOST_DISPATCH_OVERLOAD ( adds_
                         , (typename A0)
                         , bd::cpu_
                         , bd::scalar_< bd::floating_<A0> >
                         , bd::scalar_< bd::floating_<A0> >
                         )
 {
   BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
   {
     return a0+a1;
   }
 };

  // for signed integers
  BOOST_DISPATCH_OVERLOAD ( adds_
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
      using utype = bd::upgrade_t<A0>;
      return static_cast<A0>(saturate<A0>(utype(a0)+utype(a1)));
    }

    static BOOST_FORCEINLINE A0 impl( A0  a0, A0  a1
                                    , const brigand::true_ &) BOOST_NOEXCEPT
    {
      using utype = bd::as_unsigned_t<A0>;

      utype ux = a0;
      utype uy = a1;
      utype res = ux + uy;
      ux = (ux >> (sizeof(A0)*CHAR_BIT-1)) + Valmax<A0>();
      if(A0((ux ^ uy) | ~(uy ^ res)) >= Zero<A0>()) res = ux;
      return res;
    }
  };

  // for unsigned integers
  BOOST_DISPATCH_OVERLOAD ( adds_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::uint_<A0> >
                          , bd::scalar_< bd::uint_<A0> >
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
      typedef typename bd::upgrade<A0>::type utype;
      return static_cast<A0>(boost::simd::min(utype(boost::simd::Valmax<A0>()), utype(a0+a1)));
    }
    static BOOST_FORCEINLINE A0 impl( A0 a0, A0 a1
                                      , const brigand::true_ &) BOOST_NOEXCEPT
    {
      A0 res = a0 + a1;
      res |= -(res < a0);
      return res;
    }
  };
} } }


#endif

