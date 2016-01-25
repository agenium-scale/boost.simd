//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_ANDNOT_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/bitwise_andnot.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/mask2logical.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(logical_andnot_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::fundamental_<A0>, X>
                          , bs::pack_<bd::fundamental_<A1>, X>
                          )
   {
      BOOST_FORCEINLINE bs::as_logical_t<A0>  operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        return mask2logical(bitwise_andnot(genmask(a0), genmask(a1)));
      }
   };

} } }


#endif

