//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/assert_utils.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( shift_right_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    using result_t = A0;

    BOOST_FORCEINLINE result_t operator() ( A0 a0, A1 a1) const BOOST_NOEXCEPT
    {
      using itype = bd::as_integer_t<A0, signed>;
      return bitwise_cast<result_t>(shift_right(bitwise_cast<itype>(a0),a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shift_right_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::integer_<A0> >
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    using result_t = A0;

    BOOST_FORCEINLINE result_t operator() ( A0 a0, A1 a1) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG( assert_good_shift<A0>(a1)
                      , "shift_right: a shift is out of range"
                      );

      return a0 >> a1;
    }
  };
} } }


#endif
