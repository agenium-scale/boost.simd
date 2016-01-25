//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPLEMENT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPLEMENT_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/b_xor.hpp>
#include <boost/simd/function/simd/logical_xor.hpp>
#include <boost/simd/function/scalar/complement.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/allbits.hpp>

namespace boost { namespace simd {
  namespace bs = boost::simd;

  namespace ext
  {
    namespace bd = boost::dispatch;
    BOOST_DISPATCH_OVERLOAD(complement_
                           , (typename A0,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        A0 r;
        using sA0 = typename A0::value_type;
        for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
        {
          r[i] =  bs::complement(sA0(a0[i]));
        }
        return r;
//      return b_xor(bs::Allbits<A0>(), a0);
      }
    };


    BOOST_DISPATCH_OVERLOAD(complement_
                           , (typename A0,typename X)
                           , bd::cpu_
                           , bs::pack_<bs::logical_<A0>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return logical_xor(bs::True<A0>(), a0);
      }
    };

  }

  template < typename T, std::size_t N>
  BOOST_FORCEINLINE bs::pack<T, N> operator~(const bs::pack < T, N>& a0 ) BOOST_NOEXCEPT
  {
    return bs::complement(a0);
  }

} }

#endif

