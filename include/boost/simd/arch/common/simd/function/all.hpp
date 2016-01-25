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
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/hmsb.hpp>
#include <boost/simd/sdk/as_logical.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(all_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::fundamental_<A0>, X>
                          )

  {
    using sA0 = bd::scalar_of_t<A0>;
    using result = bs::as_logical_t<sA0>;
    BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
    {
      for(unsigned int i=0; i < A0::static_size; ++i)
      {
        if (!a0[i]) return {false};
      }
      return {true};
      // TODO
      //return result(hmsb(genmask(a0)) == (1ull << bs::cardinal_of<A0>::value)-1);
    }
  };

} } }

#endif

