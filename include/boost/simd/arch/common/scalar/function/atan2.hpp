//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATAN2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATAN2_HPP_INCLUDED
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/arch/common/detail/generic/invtrig.hpp>
#include <boost/simd/function/scalar/copysign.hpp>
#include <boost/simd/function/scalar/if_else.hpp>
#include <boost/simd/function/scalar/if_else_zero.hpp>
#include <boost/simd/function/scalar/is_gtz.hpp>
#include <boost/simd/function/scalar/is_inf.hpp>
#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/scalar/is_negative.hpp>
#include <boost/simd/function/scalar/is_positive.hpp>
#include <boost/simd/function/scalar/is_nan.hpp>
#include <boost/simd/function/scalar/signnz.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( atan2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      #ifndef BOOST_SIMD_NO_NANS
      if (is_nan(a0) || is_nan(a1)) return Nan<A0>();
      #endif

      #ifndef BOOST_SIMD_NO_INFINITIES
      if (is_inf(a0) && is_inf(a1))
      {
        a0 = copysign(One<A0>(), a0);
        a1 = copysign(One<A0>(), a1);
      }
      #endif
      A0 z = detail::invtrig_base<A0,tag::radian_tag, tag::not_simd_type>::kernel_atan(a0/a1);
      A0 sgn = signnz(a0);
      z = if_else(is_positive(a1), z, Pi<A0>()-z)*sgn;
      return if_else(is_eqz(a0), if_else_zero(is_negative(a1), Pi<A0>()*sgn), z);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( atan2_
                          , (typename A0)
                          , bd::cpu_
                          , bs::std_tag
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const std_tag &,  A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return std::atan2(a0, a1);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( atan2_
                          , (typename A0)
                          , bd::cpu_
                          , bs::fast_tag
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      A0 z = detail::invtrig_base<A0,tag::radian_tag, tag::not_simd_type>::kernel_atan(a0/a1);
      return if_else(is_positive(a1), z, Pi<A0>()-z)*signnz(a0);
    }
  };
} } }


#endif
