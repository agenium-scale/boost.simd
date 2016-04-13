//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_ALL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_ALL_HPP_INCLUDED

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/hmsb.hpp>
#include <boost/simd/logical.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( all_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::fundamental_<A0>, X>
                          )
  {
    using sA0 =  bd::scalar_of_t<A0>;
    BOOST_FORCEINLINE logical<sA0> operator()( const A0& a0) const BOOST_NOEXCEPT
    {
      return hmsb(genmask(a0)) == (1ull << A0::static_size)-1;
    }
  };
} } }

#endif
