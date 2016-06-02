//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_MINUS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/if_else_zero.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/plus.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( if_minus_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::fundamental_<A0>, X>
                          , bs::pack_<bd::unspecified_<A1>, X>
                          , bs::pack_<bd::unspecified_<A1>, X>
                          )
   {
     BOOST_FORCEINLINE A1 operator()(A0 const& a0, A1 const& a1, A1 const& a2) const
      {
       return a1 - if_else_zero(a0, a2);
      }
   };

   BOOST_DISPATCH_OVERLOAD( if_minus_
                           , (typename A0, typename A1, typename X)
                           , bd::cpu_
                           , bs::pack_<bd::fundamental_<A0>, X>
                           , bs::pack_<bd::floating_<A1>, X>
                           , bs::pack_<bd::floating_<A1>, X>
                          )
   {
     BOOST_FORCEINLINE A1 operator()(A0 const& a0, A1 const& a1, A1 const& a2) const
      {
        // this is a workaround for a gcc (at least 4.6) over-optimization in case or a1 and a2 are
        // equal (constant?) and invalid (inf -inf or nan) in which case the general impl sometimes
        // return 0 in place of nan in float cases.
       return a1 + if_else_zero(a0, -a2);
      }
   };
} } }

#endif
