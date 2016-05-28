//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIVROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIVROUND2EVEN_HPP_INCLUDED

#include <boost/simd/function/definition/round2even.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/copysign.hpp>
#include <boost/simd/function/scalar/is_even.hpp>
#include <boost/simd/function/scalar/is_odd.hpp>
#include <boost/simd/function/scalar/round2even.hpp>
#include <boost/simd/function/scalar/tofloat.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename A0)
                          , bd::cpu_
                          , bs::tag::round2even_
                          , bd::scalar_< bd::int64_<A0> >
                          , bd::scalar_< bd::int64_<A0> >
                          )
  {
    A0 operator() ( bd::functor<bs::tag::round2even_> const&
                  , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      using ui_t = bd::as_integer_t<A0, unsigned>;
      if (!a0) return  Zero<A0>();
      if(a1)
      {
        ui_t aa0 = bs::abs(a0);
        ui_t aa1 = bs::abs(a1);
        ui_t q = aa0/aa1;
        ui_t rx2 = 2*(aa0-q*aa1);
        if (rx2 >= aa1)
        {
          if ((rx2 == aa1) && is_even(q)) --q;
          ++q;
        }
        return copysign(A0(q), a0^a1);
      }
      else
        return ((a0>0) ? Valmax<A0>() : Valmin<A0>());
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename A0)
                          , bd::cpu_
                          , bs::tag::round2even_
                          , bd::scalar_< bd::signed_<A0> >
                          , bd::scalar_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( bd::functor<bs::tag::round2even_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      if(a1)
        return static_cast<A0 >(round2even(static_cast<double>(a0)/static_cast<double>(a1)));
      else
      {
        return (a0) ? ((a0>0) ? Valmax<A0>() : Valmin<A0>()) : Zero<A0>();
      }
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename A0)
                          , bd::cpu_
                          , bs::tag::round2even_
                          , bd::scalar_< bd::unsigned_<A0> >
                          , bd::scalar_< bd::unsigned_<A0> >
                          )
  {
    A0 operator() ( bd::functor<bs::tag::round2even_> const&
                  , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      if(a1)
      {
        A0 q = a0/a1;
        A0 rx2 = Two<A0>()*(a0-q*a1);
        if (rx2 >= a1)
        {
          if ((rx2 == a1) && is_even(q)) --q;
          ++q;
        }
        return q;
      }
      else
        return (a0) ? Valmax<A0>() : Zero<A0>();
    }
  };

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4723) // potential divide by 0
#endif

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename A0)
                          , bd::cpu_
                          , bs::tag::round2even_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( bd::functor<bs::tag::round2even_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return round2even(a0/a1);
    }
  };
} } }

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif


#endif
