//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>
//#include <boost/simd/function/cardinal_of.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/mask2logical.hpp>
#include <boost/simd/sdk/as_logical.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(logical_and_
                          , (typename A0,typename A1,typename X)
                          , bd::cpu_
                          , bs::pack_<bd::fundamental_<A0>,X>
                          , bs::pack_<bd::fundamental_<A1>,X>
                          )

  {
    using result = bs::as_logical_t<A0>;
    BOOST_FORCEINLINE result operator()( const A0& a0, const A1& a1
                                       , typename std::enable_if<
                                           cardinal_of<A1>::value == cardinal_of<A0>::value
                                         >::type* = 0
                                       ) const BOOST_NOEXCEPT
    {
      return mask2logical(bitwise_and(genmask(a0), genmask(a1)));
    }
  };

} } }


#endif

