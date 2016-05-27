//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_REVERSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_REVERSE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( reverse_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_<bd::ints64_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      return  bitwise_cast<A0>(reverse(bitwise_cast<bd::as_floating_t<A0>>(a0)));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( reverse_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_<bd::ints32_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      return  bitwise_cast<A0>(reverse(bitwise_cast<bd::as_floating_t<A0>>(a0)));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( reverse_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_<bd::integer_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      return combine( reverse(slice_high(a0)), reverse(slice_low(a0)) );
    }
  };
} } }

#endif
