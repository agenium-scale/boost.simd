//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_BITWISE_CAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_BITWISE_CAST_HPP_INCLUDED

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // bitwise cast float<->integer
  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename Target)
                          , bs::avx2_
                          , bs::pack_<bd::single_<A0>,bs::avx_>
                          , bd::target_<bs::pack_<bd::integer_<Target>,bs::avx_>>
                          )
  {
    BOOST_FORCEINLINE
    typename Target::type operator()(A0 const& a0, Target const&) const BOOST_NOEXCEPT
    {
      return _mm256_castps_si256(a0);
    }
  };

  //------------------------------------------------------------------------------------------------
  // bitwise cast double<->integer
  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename Target)
                          , bs::avx2_
                          , bs::pack_<bd::double_<A0>,bs::avx_>
                          , bd::target_<bs::pack_<bd::integer_<Target>,bs::avx_>>
                          )
  {
    BOOST_FORCEINLINE
    typename Target::type operator()(A0 const& a0, Target const&) const BOOST_NOEXCEPT
    {
      return _mm256_castpd_si256(a0);
    }
  };

  //------------------------------------------------------------------------------------------------
  // bitwise cast integer<->float
  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename Target)
                          , bs::avx2_
                          , bs::pack_<bd::integer_<A0>,bs::avx_>
                          , bd::target_<bs::pack_<bd::single_<Target>,bs::avx_>>
                          )
  {
    BOOST_FORCEINLINE
    typename Target::type operator()(A0 const& a0, Target const&) const BOOST_NOEXCEPT
    {
      return _mm256_castsi256_ps(a0);
    }
  };

  //------------------------------------------------------------------------------------------------
  // bitwise cast double<->integer
  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename Target)
                          , bs::avx2_
                          , bs::pack_<bd::integer_<A0>,bs::avx_>
                          , bd::target_<bs::pack_<bd::double_<Target>,bs::avx_>>
                          )
  {
    BOOST_FORCEINLINE
    typename Target::type operator()(A0 const& a0, Target const&) const BOOST_NOEXCEPT
    {
      return _mm256_castsi256_pd(a0);
    }
  };
} } }

#endif
