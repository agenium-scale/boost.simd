//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLIT_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLIT_MULTIPLIES_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/split.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(split_multiplies_
                          , (typename A0, typename A1, typename X, typename Y)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          , bs::pack_<bd::arithmetic_<A1>, Y>
                          , bs::pack_<bd::arithmetic_<A1>, Y>
                          )
   {
     BOOST_FORCEINLINE void operator()(A0 const& a0, A0 const& a1
                                      , A1& a2, A1& a3
 //                                      , typename std::enable_if<  //TODO
//                                        is_upgradable_to<A0,A1>::value
//                                        >::type* = 0
                                      ) const
      {
        A1 a00, a01, a10, a11;
        split(a0, a00, a01);
        split(a1, a10, a11);
        a2 = a00*a10;
        a3 = a01*a11;
      }
   };

} } }

#endif

