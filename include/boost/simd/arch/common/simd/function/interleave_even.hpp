//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <boost/simd/sdk/is_bitwise_logical.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(interleave_even_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<A0>, X>
                          , bs::pack_<bd::unspecified_<A1>, X>
                          )
   {
     A0 operator()(A0 const& a0, A1 const& a1) const
      {
        A0 that;
        const std::size_t n = bs::cardinal_of<A0>::value;
        for(std::size_t i=0;i<n;i+= 2)
        {
          that[i]   = a0[i];
          that[i+1] = a1[i];
        }
        return that;
      }
   };

   BOOST_DISPATCH_OVERLOAD(interleave_even_
                             , (typename A0, typename X)
                             , bd::cpu_
                             , bs::pack_<bs::logical_<A0>, X>
                             , bs::pack_<bs::logical_<A0>, X>
                             )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        using type = A0; //meta::as_arithmetic<A0>;
        return bitwise_cast<A0>(
          interleave_even( bitwise_cast<type>(a0), bitwise_cast<type>(a1) )
        );
      }
   };


//   #define M_IEVEN(z,n,t) (n%2 ? (t+n-1) : n)
//   BOOST_SIMD_DEFINE_SHUFFLE2(  interleave_even_, M_IEVEN, type32_ )
//   BOOST_SIMD_DEFINE_SHUFFLE2(  interleave_even_, M_IEVEN, type16_ )
//   BOOST_SIMD_DEFINE_SHUFFLE2(  interleave_even_, M_IEVEN, type8_  )
//   #undef M_IEVEN

} } }

#endif

