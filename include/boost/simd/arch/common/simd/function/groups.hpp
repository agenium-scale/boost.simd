//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GROUPS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GROUPS_HPP_INCLUDED

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/extract.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/simd/saturate.hpp>
#include <boost/simd/function/simd/slice.hpp>
#include <boost/dispatch/meta/downgrade.hpp>
#include <boost/mpl/not.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
//    BOOST_DISPATCH_OVERLOAD(groups_

//                           , (typename A0, typename X)
//                           , bd::cpu_
//                           , bs::pack_<bd::arithmetic_<A0>, X>
//                           )
//    {
//   using  = ;
//       BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
//       {
//         return eval(a0, boost::is_same<A0, result>());
//       }
//       BOOST_FORCEINLINE
//       result eval(A0 const& a0, boost::mpl::false_ const&) const
//       {
//         return eval2(a0, boost::mpl::bool_<(A0::static_size>=4)>());
//       }
//       BOOST_FORCEINLINE
//       result eval(A0 const& a0, boost::mpl::true_ const&) const
//       {
//         return a0;
//       }
//       BOOST_FORCEINLINE
//       result eval2(A0 const& a0, boost::mpl::true_ const&) const
//       {
//         typename simd::meta::vector_of< typename A0::value_type
//                                       , A0::static_size/2
//                                       >::type a00,a01;
//         bs::slice(a0,a00,a01);
//         return bs::groups(a00,a01);
//       }
//       BOOST_FORCEINLINE
//       result eval2(A0 const& a0, boost::mpl::false_ const&) const
//       {
//         return make<result>( groups( extract<0>(a0) )
//                                 , groups( extract<1>(a0) )
//                                 );
//       }
//    };

//    BOOST_DISPATCH_OVERLOAD_IF(groups_
//                              , (typename A0, typename X)
//                              , bd::cpu_
//                              , bs::pack_<bd::arithmetic_<A0>, X>
//                              , bs::pack_<bd::arithmetic_<A0>, X>
//                              )
//    {
//       using result = bd::downgrade_t<A0>;
//       BOOST_FORCEINLINE result operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
//       {
//         return group(saturate<result>(a0), saturate<result>(a1));
//       }
//    };

//    BOOST_DISPATCH_OVERLOAD_IF(groups_
//                              , (typename A0, typename X)
//                              , bd::cpu_
//                              , bs::pack_<bd::floating_<A0>, X>
//                              , bs::pack_<bd::floating_<A0>, X>
//                              )
//    {
//       using result = bd::downgrade_t<A0>;
//       BOOST_FORCEINLINE result operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
//       {
//         return group(a0, a1);
//       }
//    };

//    BOOST_DISPATCH_OVERLOAD(groups_
//                           , (typename A0, typename X)
//                           , bd::cpu_
//                           , bs::pack_<bd::floating_<A0>, X>
//                           )
//    {
//   using  = ;
//       BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
//       {
//         return group(a0);
//       }
//    };

} } }

#endif

