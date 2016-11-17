//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REC_FAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REC_FAST_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/refine_rec.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/one.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  ///////////////////////////////////////////////////////////////////////////////////////////////////
  /// fast_(rec) is raw + some Newton raphson steps if raw is really not accurate (sse1, sse2, avx, ...)
  /// and alwways treat well zeros and infinities
  ///////////////////////////////////////////////////////////////////////////////////////////////////

  BOOST_DISPATCH_OVERLOAD_IF ( rec_
                             , (typename T, typename X)
                             , (detail::is_native<X>)
                             , bd::cpu_
                             , bs::fast_tag
                             , bs::pack_<bd::unspecified_<T>, X>
                             )
  {
    BOOST_FORCEINLINE T operator()(const fast_tag &, T const& a) const BOOST_NOEXCEPT
    {
      return rec(a);
    }
  };

} } }

#endif
