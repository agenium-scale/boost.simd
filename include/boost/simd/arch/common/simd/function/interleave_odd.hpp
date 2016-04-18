//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/sdk/meta/as_arithmetic.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/is_bitwise_logical.hpp>
#include <boost/simd/sdk/meta/as_arithmetic.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/is_bitwise_logical.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/extract.hpp>
#include <boost/simd/function/simd/insert.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(interleave_odd_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<A0>, X>
                          , bs::pack_<bd::unspecified_<A1>, X>
                          )
   {
     A0 operator()(A0 const& a0, A1 const& a1) const
      {
        A0 that;
        const std::size_t n = meta::cardinal_of<A0>::value;
        for(std::size_t i=0;i<n;i+= 2)
        {
          that[i]   = a0[i+1];
          that[i+1] = a1[i+1];
        }
        return that;
      }
   };

   BOOST_DISPATCH_OVERLOAD_IF(interleave_odd_
                             , (typename A0, typename X)
                             , bd::cpu_
                             , bs::pack_<bs::logical_<A0>, X>
                             , bs::pack_<bs::logical_<A0>, X>
                             )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        using type = meta::as_arithmetic<A0>;
        return bitwise_cast<A0>(
          interleave_odd( bitwise_cast<type>(a0), bitwise_cast<type>(a1) )
        );
      }
   };


  #define M_IODD(z,n,t) (n%2 ? (t+n) : n+1)
  BOOST_SIMD_DEFINE_SHUFFLE2(  interleave_odd_, M_IODD, type32_ )
  BOOST_SIMD_DEFINE_SHUFFLE2(  interleave_odd_, M_IODD, type16_ )
  BOOST_SIMD_DEFINE_SHUFFLE2(  interleave_odd_, M_IODD, type8_  )
  #undef M_IODD

} } }

#endif

