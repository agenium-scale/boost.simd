//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/b_xor.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd {
  namespace bs = boost::simd;

  namespace ext
  {
    namespace bd = boost::dispatch;
    BOOST_DISPATCH_OVERLOAD(unary_minus_
                           , (typename A0,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        A0 r;
        for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
        {
          r[i] =  -a0[i];
        }
        return r;
//      return -a0;
//      return bs::Zero<A0>() - a0;
      }
    };

    BOOST_DISPATCH_OVERLOAD(unary_minus_
                           , (typename A0,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::floating_<A0>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        A0 r;
        for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
        {
          r[i] =  -a0[i];
        }
        return r;
//        return -a0;
//      return b_xor(bs::Mzero<A0>(),a0);
      }
    };
  }

  template < typename T, std::size_t N>
  BOOST_FORCEINLINE bs::pack<T, N> operator-(const bs::pack<T, N>& a0 )  BOOST_NOEXCEPT
  {
    return bs::unary_minus(a0);
  }

} }

#endif

