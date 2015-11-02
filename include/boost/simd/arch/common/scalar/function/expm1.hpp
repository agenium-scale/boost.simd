//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_EXPM1_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_EXPM1_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/arch/detail/generic/expm1_kernel.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/logeps.hpp>
#include <boost/simd/constant/maxlog.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/function/scalar/is_greater.hpp>
#include <boost/simd/function/scalar/is_less.hpp>
#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/scalar/is_nan.hpp>
#include <boost/simd/constant/nan.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( expm1_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0) const BOOST_NOEXCEPT
    {
    #ifndef BOOST_SIMD_NO_INVALIDS
      if(is_nan(a0)) return Nan<A0>();
    #endif
      if((a0 < Logeps<A0>())) return Mone<A0>();
      if((a0 > Maxlog<A0>())) return  Inf<A0>();
      return detail::expm1_kernel<A0>::expm1(a0);
    }
  };
} } }


#endif
