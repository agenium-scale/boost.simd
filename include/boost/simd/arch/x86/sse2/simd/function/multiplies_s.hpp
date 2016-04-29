//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MULTIPLIES_S_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MULTIPLIES_S_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/shrai.hpp>
#include <boost/simd/function/simd/split_multiplies.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/meta/upgrade.hpp>

/* No native groups for 64-bit SSE;
 * we use bit tricks instead of calling saturate. */

// TODO waiting for split_multiplies etc.
namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;

//   BOOST_DISPATCH_OVERLOAD ( multiplies_
//                           , (typename A0)
//                           , bs::sse2_
//                           , bs::pack_<bd::int32_<A0>, bs::sse_>
//                           , bs::pack_<bd::int32_<A0>, bs::sse_>
//                          )
//   {
//     BOOST_FORCEINLINE A0 operator() ( const A0 & a0
//                                     , const A0 & a1 ) const BOOST_NOEXCEPT
//     {
//       using stype  = bd::scalar_of_t<A0>;
//       using untype = bd::as_unsigned_t<A0>;
//       using utype  = bd::upgrade_t<A0>;

//       utype res0, res1;
//       split_multiplies(a0, a1, res0, res1);

//       untype res2 = shrai(bitwise_cast<untype>(a0 ^ a1), sizeof(stype)*CHAR_BIT-1)
//                   + static_cast<typename bd::scalar_of<untype>::type>(Valmax<stype>());

//       A0 hi = group( shrai(res0, sizeof(stype)*CHAR_BIT)
//                    , shrai(res1, sizeof(stype)*CHAR_BIT)
//                    );
//       A0 lo = group(res0, res1);

//       return if_else( hi != shrai(lo, sizeof(stype)*CHAR_BIT-1)
//                     , bitwise_cast<A0>(res2)
//                     , lo
//                     );
//     }
//   };

//   BOOST_DISPATCH_OVERLOAD ( multiplies_
//                           , (typename A0)
//                           , bs::sse2_
//                           , bs::pack_<bd::uint32_<A0>, bs::sse_>
//                           , bs::pack_<bd::uint32_<A0>, bs::sse_>
//                          )
//   {
//     BOOST_FORCEINLINE A0 operator() ( const A0 & a0
//                                     , const A0 & a1 ) const BOOST_NOEXCEPT
//     {
//       using stype  = bd::scalar_of_t<A0>;
//       using utype  = bd::upgrade_t<A0>;

//       utype res0, res1;
//       split_multiplies(a0, a1, res0, res1);

//       return group(res0, res1)
//            | genmask( group( shrai(res0, sizeof(stype)*CHAR_BIT)
//                            , shrai(res1, sizeof(stype)*CHAR_BIT)
//                            )
//                     );
//     }
//   };

} } }

#endif
