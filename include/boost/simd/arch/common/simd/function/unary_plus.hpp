//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_UNARY_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_UNARY_PLUS_HPP_INCLUDED
#include <boost/simd/pack.hpp>

namespace boost { namespace simd {

  namespace bs = boost::simd;

  namespace ext
  {
    namespace bd = boost::dispatch;
    BOOST_DISPATCH_OVERLOAD(unary_plus_
                           , (typename A0,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return a0;
      }
    };

  }

  template < typename T, std::size_t N>
  BOOST_FORCEINLINE bs::pack<T, N> operator+(const bs::pack<T, N>& a0 ) BOOST_NOEXCEPT
  {
    return bs::unary_plus(a0);
  }

} }

#endif

