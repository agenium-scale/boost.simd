//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ALIGNED_STORE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ALIGNED_STORE_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/config.hpp>
#include <tuple>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  /// INTERNAL ONLY - SIMD aligned_store in simd emulation without offset
  BOOST_DISPATCH_OVERLOAD ( aligned_store_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<A0>,bs::simd_emulation_>
                          , bd::pointer_<bd::scalar_<bd::unspecified_<A1>>,1u>
                          )
  {

    BOOST_FORCEINLINE void operator()(const A0& a0, A1  a1) const BOOST_NOEXCEPT
    {
      bs::store(a0, a1);
    }
  };


} } }

#endif
