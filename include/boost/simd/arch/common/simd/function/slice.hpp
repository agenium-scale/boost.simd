//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SLICE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SLICE_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(slice_
                          , (typename A0, typename A1, typename X, typename Y)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<A0>, Y>
                          , bs::pack_<bd::unspecified_<A1>, X>
                          , bs::pack_<bd::unspecified_<A1>, X>
                          )
   {
     BOOST_FORCEINLINE void operator()(A0 const& a0,A1& a1, A1& a2) const
      {
        for(size_t i=0; i!=A1::static_size; ++i)
        {
          a1[i] = a0[i];
          a2[i] = a0[i+A1::static_size];
        }
      }
   };

   BOOST_DISPATCH_OVERLOAD(slice_
                             , (typename A0, typename A1, typename X, typename Y)
                             , bd::cpu_
                             , bs::pack_<bs::logical_<A0>, Y>
                             , bs::pack_<bs::logical_<A1>, X>
                             , bs::pack_<bs::logical_<A1>, X>
                             )
   {
     BOOST_FORCEINLINE void operator()(A0 const& a0,A1& a1, A1& a2) const
      {
        using type0 = typename A0::type;
        using type1 = typename A1::type;
        type1 l1,l2;
        bs::slice(bitwise_cast<type0>(a0),l1,l2);
        a1 = bitwise_cast<A1>(l1);
        a2 = bitwise_cast<A1>(l2);
      }
   };
} } }

#endif
