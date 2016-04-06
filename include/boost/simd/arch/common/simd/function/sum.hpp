//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SUM_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SUM_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/function/simd/splatted_sum.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(sum_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
   {
      using result = typename A0::value_type;
     BOOST_FORCEINLINE result operator()(A0 const& a0) const
      {
        return splatted_sum(a0)[0];
      }
   };

} } }

#endif

