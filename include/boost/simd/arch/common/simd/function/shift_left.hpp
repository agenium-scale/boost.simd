//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd {
  namespace bs = boost::simd;

  namespace ext
  {
    namespace bd = boost::dispatch;
    BOOST_DISPATCH_OVERLOAD(shift_left_
                           , (typename A0,typename A1,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::floating_<A0>,X>
                           , bd::scalar_<bd::integer_<A1>>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1) const BOOST_NOEXCEPT
      {
        using int_type = bd::as_integer_t<A0, signed>;
        BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_left: a shift is out of range");
        return bitwise_cast<A0>( shift_left(bitwise_cast<int_type>(a0), a1) );
      }
    };

    BOOST_DISPATCH_OVERLOAD(shift_left_
                           , (typename A0,typename A1,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           , bd::scalar_<bd::integer_<A1>>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1) const BOOST_NOEXCEPT
      {
        A0 r;
        for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
        {
          r[i] = a0[i] << a1;
        }
        return r;
      }
    };

    BOOST_DISPATCH_OVERLOAD(shift_left_
                           , (typename A0,typename A1,typename X)
                           , bd::cpu_
                           , bs::pack_<bd::arithmetic_<A0>,X>
                           , bs::pack_<bd::integer_<A1>,X>
                           )

    {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1) const BOOST_NOEXCEPT
      {
        A0 r;
        for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
        {
          r[i] = a0[i] << a1[i];
        }
        return r;
      }
    };
  }

  template < typename T, typename I, std::size_t N>
  BOOST_FORCEINLINE bs::pack<T, N> operator << ( const bs::pack<T, N>& a0
                                            , const I& a1)  BOOST_NOEXCEPT
  {
    return bs::shift_left(a0, a1);
  }


} }

#endif

