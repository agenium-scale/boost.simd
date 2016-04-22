//==================================================================================================
/**

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD_IF( unary_minus_
                            , (typename A0,typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::arithmetic_<A0>,X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0) const BOOST_NOEXCEPT
    {
      return bs::Zero<A0>() - a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF( unary_minus_
                            , (typename A0,typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::floating_<A0>,X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0) const BOOST_NOEXCEPT
    {
      return bitwise_xor(bs::Mzero<A0>(),a0);
    }
  };
} } }

#endif
