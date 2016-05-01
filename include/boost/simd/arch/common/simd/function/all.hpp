//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ALL_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/hmsb.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF( all_
                            , (typename A0, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::fundamental_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE bool operator()(const A0& a0) const BOOST_NOEXCEPT
    {
      using count = std::integral_constant<std::size_t, (1ull << A0::static_size)-1>;
      return hmsb(genmask(a0)) == count::value;
    }
  };
} } }

#endif
