//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REMROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REMROUND2EVEN_HPP_INCLUDED

#include <boost/simd/function/div.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/round2even.hpp>
#include <boost/simd/function/selsub.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
/////////////////////////////////////////////////////////////////////////////
// The remround2even() function computes the remround2even of dividing x by y.  The
// return value is x-n*y, where n is the value x / y, rounded to the nearest
// integer.  If the boost::simd::absolute value of x-n*y is 0.5, n is chosen
// to be even.
/////////////////////////////////////////////////////////////////////////////

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( rem_
                          , (typename A0)
                          , bd::cpu_
                          , bs::tag::round2even_
                          , bd::generic_< bd::signed_<A0> >
                          , bd::generic_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (bd::functor<bs::tag::round2even_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return selsub(is_nez(a1),a0,
                    simd::multiplies(div(round2even, a0, a1), a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rem_
                          , (typename A0)
                          , bd::cpu_
                          , bs::tag::round2even_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (bd::functor<bs::tag::round2even_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0-div(round2even, a0, a1)*a1;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rem_
                          , (typename A0)
                          , bd::cpu_
                          , bs::fast_tag
                          , bs::tag::round2even_
                          , bd::generic_< bd::signed_<A0> >
                          , bd::generic_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &
                                    , bd::functor<bs::tag::round2even_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0-fast_(div)(round2even, a0, a1)*a1;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rem_
                          , (typename A0)
                          , bd::cpu_
                          , bs::std_tag
                          , bs::tag::round2even_
                          , bd::generic_< bd::signed_<A0> >
                          , bd::generic_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const std_tag &
                                    , bd::functor<bs::tag::round2even_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return std::remainder(a0, a1);
    }
  };
} } }


#endif
