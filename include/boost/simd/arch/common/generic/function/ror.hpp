//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROR_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( ror_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::integer_<A0> >
                          , bd::generic_< bd::integer_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A0 const& a1
                                    , typename std::enable_if<bd::cardinal_of<A1>::value
                                     == bd::cardinal_of<A0>::value>::type* = 0
                                    ) const
    {
      using s_t = bd::scalar_of_t<A0>;
      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "ror : rotation is out of range");

      s_t const width = sizeof(s_t)*CHAR_BIT;
      return shr(a0, a1) | shift_left(a0, (width-splat<A0>(a1)) & (width-1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( ror_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::integer_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A1 const& a1
                                    , typename std::enable_if<bd::cardinal_of<A1>::value
                                     == bd::cardinal_of<A0>::value>::type* = 0
                                    ) const
    {
      using i_t = bd::as_integer_t<A0, unsigned>;
      return bitwise_cast<A0>( ror ( bitwise_cast<i_t>(a0)
                                            , splat<i_t>(a1)
                                            )
                                      );
    }
  };
} } }


#endif
