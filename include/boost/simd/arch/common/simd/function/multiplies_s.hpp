//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MULTIPLIES_S_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MULTIPLIES_S_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
//#include <boost/simd/meta/is_upgradable.hpp>
#include <boost/simd/function/simd/groups.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/split_multiplies.hpp>
#include <boost/simd/function/saturated.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(multiplies_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::saturated_tag
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(const saturated_tag &
                                     ,  const A0& a0, const A0& a1
                                    ) const BOOST_NOEXCEPT
      {
        return a0*a1;
      }
   };
// TODO waiting for split things etc.
//    BOOST_DISPATCH_OVERLOAD(multiplies_
//                           , (typename A0, typename X)
//                           , bd::cpu_
//                           , bs::saturated_tag
//                           , bs::pack_<bd::integer_<A0>, X>
//                           , bs::pack_<bd::integer_<A0>, X>
//                           )
//    {
//       BOOST_FORCEINLINE A0 operator()(const saturated_tag &
//                                      ,  const A0& a0, const A0& a1
//  //                                    , typename std::enable_if< // TODO
//  //                                      bs::is_upgradable_on_ext_t<A0>::value
//  //                                       >::type* = 0
//                                   ) const BOOST_NOEXCEPT
//       {
// //         using utype = bd::upgrade_t<A0>;
// //         utype res0, res1;
// //         split_multiplies(a0, a1, res0, res1);
// //         return groups(res0, res1);
//       }
//    };

} } }

#endif

