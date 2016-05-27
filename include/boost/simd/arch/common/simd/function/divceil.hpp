//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIVCEIL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIVCEIL_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/ceil.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/simd/split.hpp>
#include <boost/simd/function/simd/tofloat.hpp>
#include <boost/simd/function/simd/toint.hpp>
#include <boost/simd/function/simd/touint.hpp>
#include <boost/simd/detail/dispatch/meta/upgrade.hpp>
#include <utility>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD(div_
                         , (typename A0, typename X)
                         , bd::cpu_
                         , bs::tag::ceil_
                         , bs::pack_<bd::arithmetic_<A0>, X>
                         , bs::pack_<bd::arithmetic_<A0>, X>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( bd::functor<bs::tag::ceil_> const&
                                   , const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      A0 r;
      for(unsigned int i=0; i <A0::static_size ; i++)
      {
        r[i] = div(ceil, a0[i], a1[i]);
      }
      return r;
    }
  };
  BOOST_DISPATCH_OVERLOAD_IF(div_
                            , (typename A0, typename X)
                            , (bd::is_upgradable<A0>)
                            , bd::cpu_
                            , bs::tag::ceil_
                            , bs::pack_<bd::int_<A0>, X>
                            , bs::pack_<bd::int_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()( bd::functor<bs::tag::ceil_> const&
                                   , const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      using ivtype = bd::upgrade_t<A0>;
      ivtype a0l, a0h, a1l, a1h;
      std::tie(a0l, a0h) = bs::split(a0);
      std::tie(a1l, a1h) = bs::split(a1);
      ivtype d0 = saturated_(toint)(div(ceil, tofloat(a0l), tofloat(a1l)));
      ivtype d1 = saturated_(toint)(div(ceil, tofloat(a0h), tofloat(a1h)));
      return saturated_(group)(d0, d1);
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF(div_
                            , (typename A0, typename X)
                            , (bd::is_upgradable<A0>)
                            , bd::cpu_
                            , bs::tag::ceil_
                            , bs::pack_<bd::uint_<A0>, X>
                            , bs::pack_<bd::uint_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()( bd::functor<bs::tag::ceil_> const&
                                   , const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      using ivtype = bd::upgrade_t<A0>;
      ivtype a0l, a0h, a1l, a1h;
      std::tie(a0l, a0h) = bs::split(a0);
      std::tie(a1l, a1h) = bs::split(a1);
      ivtype d0 = saturated_(touint)(div(ceil, tofloat(a0l), tofloat(a1l)));
      ivtype d1 = saturated_(touint)(div(ceil, tofloat(a0h), tofloat(a1h)));
      return saturated_(group)(d0, d1);
    }
  };

  BOOST_DISPATCH_OVERLOAD(div_
                         , (typename A0, typename X)
                         , bd::cpu_
                         , bs::tag::ceil_
                         , bs::pack_<bd::ints8_<A0>, X>
                         , bs::pack_<bd::ints8_<A0>, X>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( bd::functor<bs::tag::ceil_> const&
                                   , const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      using ivtype = bd::upgrade_t<A0>;
      ivtype a0l, a0h, a1l, a1h;
      std::tie(a0l, a0h) = bs::split(a0);
      std::tie(a1l, a1h) = bs::split(a1);
      ivtype d0 = div(ceil, a0l, a1l);
      ivtype d1 = div(ceil, a0h, a1h);
      return saturated_(group)(d0, d1);
    }
  };

  BOOST_DISPATCH_OVERLOAD(div_
                         , (typename A0, typename X)
                         , bd::cpu_
                         , bs::tag::ceil_
                         , bs::pack_<bd::floating_<A0>, X>
                         , bs::pack_<bd::floating_<A0>, X>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( bd::functor<bs::tag::ceil_> const&
                                   , const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      return bs::ceil(a0/a1);
    }
  };

} } }

#endif

