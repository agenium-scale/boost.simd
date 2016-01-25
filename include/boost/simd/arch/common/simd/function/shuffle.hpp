//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED

#include <boost/simd/pack.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  template < int N1, int N2,  int N3, int N4, typename T>
  BOOST_FORCEINLINE T shuffle(const T & a) BOOST_NOEXCEPT
  {
    return {a[N1],a[N2],a[N3],a[N4]};
  }
  template < int N1, int N2, int N3, int N4, typename T>
  BOOST_FORCEINLINE T shuffle(const T & a0, const T & a1) BOOST_NOEXCEPT
  {
    static const int N = 4;
    return { N1 <  N ? a0[N1] : a1[N1-N]
        ,    N2 <  N ? a0[N2] : a1[N2-N]
        ,    N3 <  N ? a0[N3] : a1[N3-N]
        ,    N4 <  N ? a0[N4] : a1[N4-N]
        };
  }
  template < int N1, int N2, typename T>
  BOOST_FORCEINLINE T shuffle(const T & a) BOOST_NOEXCEPT
  {
    return {a[N1],a[N2]};
  }
  template < int N1, int N2, typename T>
  BOOST_FORCEINLINE T shuffle(const T & a0, const T & a1) BOOST_NOEXCEPT
  {
    static const int N = 2;
    return { N1 <  N ? a0[N1] : a1[N1-N]
        ,    N2 <  N ? a0[N2] : a1[N2-N]
        };
  }

} } }


#endif

