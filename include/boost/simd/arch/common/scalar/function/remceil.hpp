//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REMCEIL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REMCEIL_HPP_INCLUDED

#include <boost/simd/function/div.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
/////////////////////////////////////////////////////////////////////////////
// The remceil() function computes the remceil of dividing x by y.  The
// return value is x-n*y, where n is the value x / y, rounded toward +infinity
/////////////////////////////////////////////////////////////////////////////

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( rem_
                          , (typename A0)
                          , bd::cpu_
                          , bs::tag::ceil_
                          , bd::generic_< bd::signed_<A0> >
                          , bd::generic_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (bd::functor<bs::tag::ceil_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
<<<<<<< 81e2c23546df4375f8f87c00d60dfd821e8af64b:include/boost/simd/arch/common/scalar/function/remainder.hpp
      return if_minus(is_nez(a1),a0,
                    simd::multiplies(div(iround2even, a0, a1), a1));
=======
      return selsub(is_nez(a1),a0,
                    simd::multiplies(div(ceil, a0, a1), a1));
>>>>>>> rem now follows the div scheme:include/boost/simd/arch/common/scalar/function/remceil.hpp
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rem_
                          , (typename A0)
                          , bd::cpu_
                          , bs::tag::ceil_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (bd::functor<bs::tag::ceil_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0-div(ceil, a0, a1)*a1;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rem_
                          , (typename A0)
                          , bd::cpu_
                          , bs::fast_tag
                          , bs::tag::ceil_
                          , bd::generic_< bd::signed_<A0> >
                          , bd::generic_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &
                                    , bd::functor<bs::tag::ceil_> const&
                                    , A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0-fast_(div)(ceil, a0, a1)*a1;
    }
  };
} } }


#endif
