//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_BITGET_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_BITGET_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/assert_utils.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( bitget_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bd::generic_< bd::integer_<A1> >
                          )
  {
    using result_t = bd::as_integer_t<A0, unsigned>;

    static_assert
      ( bd::cardinal_of<A0>::value == bd::cardinal_of<A1>::value
      , "boost.simd cardinalities are inconsistent in biget call"
      );

    BOOST_FORCEINLINE result_t operator() ( A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      using sA0 = bd::scalar_of_t<A0>;
      A1 c = splat<A1>(sizeof(sA0)*CHAR_BIT);
      BOOST_ASSERT_MSG(assert_good_shift<A0>(c-a1)&&assert_good_shift<A0>(dec(c))
                      , "bitget :index is out of range");

      return shr(shift_left(bitwise_cast<result_t>(a0), c-a1), dec(c));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( bitget_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    using result_t =  bd::as_integer_t<A0, unsigned>;

    BOOST_FORCEINLINE result_t operator() ( A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      using sA0 = bd::scalar_of_t<A0>;
      A1 c = sizeof(sA0)*CHAR_BIT;
      BOOST_ASSERT_MSG(assert_good_shift<A0>(c-a1)&&assert_good_shift<A0>(dec(c))
                      , "bitget :index is out of range");
      return shr(shift_left(bitwise_cast<result_t>(a0), c-a1), dec(c));
    }
  };
} } }


#endif
