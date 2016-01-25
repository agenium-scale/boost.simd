//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_XOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_XOR_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd {

  namespace bs = boost::simd;

  namespace ext
  {
    namespace bd = boost::dispatch;
    BOOST_DISPATCH_OVERLOAD(bitwise_xor_
                           , (typename A0,typename A1,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           , bs::pack_<bd::arithmetic_<A1>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1
                                     , typename std::enable_if<
                                       sizeof(A1) == sizeof(A0)
                                       >::type* = 0
        ) const BOOST_NOEXCEPT
        {
          return bitwise_xor(a0, bitwise_cast<A0>(a1));
        }
    };

    BOOST_DISPATCH_OVERLOAD(bitwise_xor_
                           , (typename A0,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1
                                     ) const BOOST_NOEXCEPT
      {
        A0 r;
        using sA0 = typename A0::value_type;
        for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
        {
          r[i] =  bitwise_xor(sA0(a0[i]), sA0(a1[i]));
        }
        return r;
      }
    };

    BOOST_DISPATCH_OVERLOAD(bitwise_xor_
                           , (typename A0,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::floating_<A0>,X>
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1
                                     ) const BOOST_NOEXCEPT
      {
        using iA0 = bd::as_integer_t<A0>;
        return bitwise_cast<A0>(bitwise_xor(bitwise_cast<iA0>(a0), a1));
      }
    };
  }

template < typename T0, typename T1, std::size_t N1, std::size_t N2>
BOOST_FORCEINLINE bs::pack<T0, N1> operator^( const bs::pack<T0, N1>& a0
                                            , const bs::pack<T1, N2>& a1
                                            )  BOOST_NOEXCEPT
  {
    return bs::bitwise_xor(a0, a1);
  }

} }

#endif

