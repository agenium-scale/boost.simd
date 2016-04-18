
//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_LOOKUP_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_LOOKUP_HPP_INCLUDED

#include <boost/simd/function/simd/shift_left.hpp>
#include <boost/simd/function/simd/plus.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( lookup_
                          , (typename A0)
                          , bs::ssse3_
                          , bs::pack_<bd::type8_<A0>, bs::sse_>
                          , bs::pack_<bd::ints8_<A0>, bs::sse_>
                        )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return _mm_shuffle_epi8(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( lookup_
                          , (typename A0)
                          , bs::ssse3_
                          , bs::pack_<bd::type16_<A0>, bs::sse_>
                          , bs::pack_<bd::ints16_<A0>, bs::sse_>
                        )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
//     typedef typename A0::template rebind<char>::type  type8;
     using type8 = pack < char, 16 >;
     const type8 inc = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
     const type8 dup = {0,0,2,2,4,4,6,6,8,8,10,10,12,12,14,14};
     const type8 i1 = _mm_shuffle_epi8(shift_left(a1, 1), dup);
     return _mm_shuffle_epi8(simd::bitwise_cast<type8>(a0),i1+inc);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( lookup_
                          , (typename A0)
                          , bs::ssse3_
                          , bs::pack_<bd::type32_<A0>, bs::sse_>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                        )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      //    typedef typename A0::template rebind<char>::type  type8;
     using type8 = pack < char, 16 >;

     const type8 inc = {  0, 1, 2, 3, 0, 1, 2, 3
                        , 0, 1, 2, 3, 0, 1, 2, 3};
     const type8 dup = {  0, 0, 0, 0, 4, 4, 4, 4
                        , 8, 8, 8, 8, 12, 12, 12, 12};
     const type8 i1 = _mm_shuffle_epi8(shift_left(a1, 2), dup);
     return simd::bitwise_cast<A0>(_mm_shuffle_epi8(simd::bitwise_cast<type8>(a0), i1+inc));
    }
  };
   BOOST_DISPATCH_OVERLOAD ( lookup_
                          , (typename A0)
                          , bs::ssse3_
                          , bs::pack_<bd::type64_<A0>, bs::sse_>
                          , bs::pack_<bd::ints64_<A0>, bs::sse_>
                        )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      //    typedef typename A0::template rebind<char>::type  type8;
     using type8 = pack < char, 16 >;

     const type8 inc = {  0, 1, 2, 3, 4, 5, 6, 7
                        , 0, 1, 2, 3, 4, 5, 6, 7};
     const type8 dup = {  0, 0, 0, 0, 0, 0, 0, 0
                        , 8, 8, 8, 8, 8, 8, 8, 8 };
     const type8 i1 = _mm_shuffle_epi8(shift_left(a1, 3), dup);
     return simd::bitwise_cast<A0>(_mm_shuffle_epi8(simd::bitwise_cast<type8>(a0), i1+inc));
    }
  };

} } }

#endif
