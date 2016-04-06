//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REVERSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REVERSE_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/sdk/is_bitwise_logical.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD(reverse_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bs::logical_<A0>, X>
                          )
   {
     template<class A0_>
     BOOST_FORCEINLINE typename enable_if< bs::is_bitwise_logical<A0_>, A0>::type
     operator()( const A0_& a0) const BOOST_NOEXCEPT
     {
       using type = pack<typename A0::value_type,A0::static_size>;
       return bitwise_cast<A0>(reverse( bitwise_cast<type>(a0)));
      }
   };
} } }

#endif
