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
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ARG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ARG_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/simd/if_allbits_else.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#endif
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/simd/if_else_zero.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( arg_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      // a0 >= 0 -> 0, a0 < 0 ->Pi, a0 is Nan -> Nan
      A0 r = if_else_zero(is_ltz(a0),Pi<A0>());
      #ifndef BOOST_SIMD_NO_NANS
        return if_allbits_else(is_nan(a0),r);
      #else
        return r;
      #endif
    }
  };
} } }


#endif
