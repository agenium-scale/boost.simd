//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_ARCH_LOG1P_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/sdk/config.hpp>
#include <nt2/function/simd/divides.hpp>
#include <nt2/function/simd/is_nez.hpp>
#include <nt2/function/simd/log.hpp>
#include <nt2/function/simd/minus.hpp>
#include <nt2/function/simd/minusone.hpp>
#include <nt2/function/simd/oneplus.hpp>
#include <nt2/function/simd/seladd.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <nt2/constant/inf.hpp>
#include <nt2/function/simd/if_else.hpp>
#include <nt2/function/simd/is_equal.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;

    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
    {
      result_type u = oneplus(a0);
      result_type r = seladd(is_nez(u),
                             log(u),
                             (a0-minusone(u))/u); // cancels errors with IEEE arithmetic
      #ifndef BOOST_SIMD_NO_INFINITIES
      r = if_else(eq(u, Inf<A0>()),u, r);
      #endif
      return r;
    }
  };
} }

#endif
