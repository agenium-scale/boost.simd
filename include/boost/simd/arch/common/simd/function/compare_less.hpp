//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_LESS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_LESS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>


namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(compare_less_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          )
   {
     BOOST_FORCEINLINE bool operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
     {
       for(std::size_t i=0;i<A0::static_size;++i)
        {
          if (a0[i] < a1[i])  return true;
          if (a1[i] < a0[i])  return false;
        }
          return false;
      }
   };

} } }

#endif

