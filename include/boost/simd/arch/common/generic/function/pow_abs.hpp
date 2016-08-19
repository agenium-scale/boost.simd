//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_POW_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_POW_ABS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( pow_abs_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bs::fast_tag
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const fast_tag &, A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      return bs::exp(a1*bs::log(bs::abs(a0)));
    }
  };


} } }


#endif
