//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_HYPOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_HYPOT_HPP_INCLUDED

#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( hypot_
                          , (typename A0)
                          , bd::cpu_
                          , bs::fast_tag
                          , bd::generic_<bd::floating_<A0> >
                          , bd::generic_<bd::floating_<A0> >
                          )
  {

    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 const& a0, A0 const& a1
                                    ) const BOOST_NOEXCEPT
    {
      return boost::simd::sqrt(bs::fma(a0, a0, sqr(a1)));
    }
  };
} } }


#endif
