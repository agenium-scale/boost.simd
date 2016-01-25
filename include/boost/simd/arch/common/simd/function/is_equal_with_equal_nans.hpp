//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/sdk/as_logical.hpp>
#include <boost/simd/function/simd/is_equal.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#include <boost/simd/function/simd/logical_and.hpp>
#include <boost/simd/function/simd/logical_or.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(is_equal_with_equal_nans_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE bs::as_logical_t<A0>  operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return logical_or(eq(a0,a1), logical_and(bs::is_nan(a0), bs::is_nan(a1)));
      }
   };

   BOOST_DISPATCH_OVERLOAD(is_equal_with_equal_nans_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::fundamental_<A0>, X>
                          , bs::pack_<bd::fundamental_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE bs::as_logical_t<A0>   operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return is_equal(a0,a1);
      }
   };

} } }

#endif

