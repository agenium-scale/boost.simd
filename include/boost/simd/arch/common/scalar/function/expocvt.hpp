//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPOCVT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPOCVT_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/nbexponentbits.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( expocvt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_<bd::floating_<A0> >
                          )
  {
    using result =  bd::as_integer_t<A0, unsigned>;
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(is_flint(a0), "parameter is not a flint");
//      return a0+Maxexponent<A0>();
      return std::ldexp(A0(1), result(a0));
    }
  };

} } }


#endif
