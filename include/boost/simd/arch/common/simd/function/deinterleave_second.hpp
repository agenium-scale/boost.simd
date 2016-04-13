//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/is_bitwise_logical.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/meta/cardinal_of.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(deinterleave_second_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<A0>, X>
                          , bs::pack_<bd::unspecified_<A1>, X>
                          )
   {
     A0 operator()(A0 const& a0, A1 const& a1) const
      {
        A0 that;
        const std::size_t middle = bs::cardinal_of<A0>::value/2;
        for(std::size_t i=0,j=middle;i<middle;++i,++j)
        {
          that[i] = a0[(i*2)+1];
          that[j] = a1[(i*2)+1];
        }
        return that;
      }
   };

   BOOST_DISPATCH_OVERLOAD(deinterleave_second_
                           , (typename A0, typename X)
                           , bd::cpu_
                           , bs::pack_<bs::logical_<A0>, X>
                           , bs::pack_<bs::logical_<A0>, X>
                           )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        using type =  bs::pack<typename A0::value_type>;//meta::as_arithmetic<A0>;
        return bitwise_cast<A0>(
          deinterleave_second( bitwise_cast<type>(a0), bitwise_cast<type>(a1) )
        );
      }
   };

} } }

#endif

