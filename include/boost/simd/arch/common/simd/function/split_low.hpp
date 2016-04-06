//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLIT_LOW_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLIT_LOW_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/preprocessor/make.hpp>
#include <boost/simd/sdk/meta/is_upgradable.hpp>
#include <boost/simd/preprocessor/make.hpp>
#include <boost/simd/sdk/meta/is_upgradable.hpp>
#include <boost/simd/function/simd/extract.hpp>
#include <boost/simd/function/simd/make.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD_IF(split_low_

                             , (typename A0, typename X)
                             , bd::cpu_
                             , bs::pack_<bd::arithmetic_<A0>, X>
                             )
   {
      using result = bd::upgrade_t<A0>;
     BOOST_FORCEINLINE result operator()(const A0& a0) const
      {
        return eval(a0,typename simd::meta::cardinal_of<result>::type());
      }
      #define M0(z, n, t) static_cast<sA1>(extract<n>(a0))
      BOOST_SIMD_PP_IMPLEMENT_WITH_MAKE(1, M0)
      #undef M0
   };

} } }

#endif

