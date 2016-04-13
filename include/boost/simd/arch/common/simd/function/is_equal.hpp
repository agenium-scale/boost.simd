//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD(is_equal_
                          , (typename A0,typename X)
                          , bd::cpu_
                          , bs::pack_<bs::logical_<A0>,X>
                          , bs::pack_<bs::logical_<A0>,X>
                          )

  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1
                                   , typename std::enable_if<sizeof(A0) == sizeof(typename A0::type)>::type* = 0
                                   ) const BOOST_NOEXCEPT
    {
      using base_t = typename A0::type;
      using cast_t = bd::as_integer_t<base_t>;
      return bitwise_cast<A0> ( is_equal( bitwise_cast<cast_t>(a0)
                                        , bitwise_cast<cast_t>(a1)
                                        )
                              );
    }
  };

  BOOST_DISPATCH_OVERLOAD(is_equal_
                         , (typename A0,typename X)
                         , bd::cpu_
                         , bs::pack_<bd::arithmetic_<A0>,X>
                         , bs::pack_<bd::arithmetic_<A0>,X>
                         )

  {
    using result = bs::as_logical_t<A0> ;
    BOOST_FORCEINLINE result operator()( const A0& a0 , const A0& a1
                                   , typename std::enable_if<sizeof(A0) == sizeof(result)>::type* = 0
                                   ) const BOOST_NOEXCEPT
    {
      result r;
      for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
      {
        r[i] = (a0[i] == a1[i]);
      }
      return r;
    }
  };

} } }

#endif

