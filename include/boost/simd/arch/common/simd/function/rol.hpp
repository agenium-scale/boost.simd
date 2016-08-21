//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROL_HPP_INCLUDED

#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/bitwise_or.hpp>
#include <boost/simd/function/simd/dec.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/shift_left.hpp>
#include <boost/simd/function/simd/shift_right.hpp>
#include <boost/simd/function/simd/splat.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF ( rol_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_< bd::integer_<A0>, X>
                          , bs::pack_< bd::integer_<A1>, X>
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A1 const& a1
//TODO                                     , typename std::enable_if<bs::cardinal_of<A1>::value
//                                      == bs::cardinal_of<A0>::value, int>::type* = 0
      ) const
    {
      using s_t = bd::scalar_of_t<A0>;
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "rol : rotation is out of range");

      s_t const width = sizeof(s_t)*CHAR_BIT;
      return shift_left(a0, a1) | shift_right(a0, (width-a1) & (dec(width))); //seems odd to me JTL
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF ( rol_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_< bd::floating_<A0>, X>
                          , bs::pack_< bd::integer_<A1>, X>
  )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A1 const& a1
//  TODO                                   , typename std::enable_if<bs::cardinal_of<A1>::value
//                                      == bs::cardinal_of<A0>::value, int>::type* = 0
                                    ) const
    {
      using i_t = bd::as_integer_t<A0, unsigned>;
      return bitwise_cast<A0>( rol ( bitwise_cast<i_t>(a0)
                                   , i_t(a1)
                                   )
                             );
    }
  };
} } }


#endif
