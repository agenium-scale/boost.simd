//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SATURATE_AT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SATURATE_AT_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
//TODO PERHAPS SUPPRESS

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
//   BOOST_DISPATCH_OVERLOAD ( boost::simd::tag::saturate_at_
//                           , (typename A0, typename Tag)
//                           , bd::cpu_
//                           , bd::generic_<signed_<A0> >
//                           , bd::target_<fundamental_<Tag>>
//                           )
//   {
//     using result_type = A0;
//     BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
//     {
//       typename dispatch::make_functor<Tag, A0>::type callee;
//       const A0 z = callee( dispatch::meta::as_<A0>() );
//       return min(z, max(unary_minus(z), a0));
//     }
//   };

//   BOOST_DISPATCH_OVERLOAD ( boost::simd::tag::saturate_at_<Tag>

//                           , (typename A0, Tag)
//                              , bd::cpu_
//                                     , bd::generic_<bd::unsigned_<A0> >
//                                    )
//   {
//     using result_type = A0;
//     BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
//     {
//       typename dispatch::make_functor<Tag, A0>::type callee;
//       return min(a0, callee( dispatch::meta::as_<A0>() ));
//     }
//   };
} } }


#endif
