//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/assert.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD(shift_right_
                         , (typename A0,typename A1,typename X)
                         , bd::cpu_
                         , bs::pack_<bd::floating_<A0>,X>
                         , bd::scalar_<bd::integer_<A1>>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1) const BOOST_NOEXCEPT
    {
      using int_type = bd::as_integer_t<A0, signed>;
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_right: a shift is out of range");
      return bitwise_cast<A0>( shift_right(bitwise_cast<int_type>(a0), a1) );
    }
  };
} } }

#endif
