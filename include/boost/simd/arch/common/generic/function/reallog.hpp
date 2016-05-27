//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REALLOG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REALLOG_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/assert.hpp>
#include <boost/simd/operator/function/details/assert_utils.hpp>
#include <boost/simd/function/simd/is_nltz.hpp>
#include <boost/simd/function/simd/log.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
 BOOST_DISPATCH_OVERLOAD ( reallog_
                          , (typename A0)
                             , bd::cpu_
                            , bd::generic_< bd::floating_<A0> >
                            )
 {
   BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
   {
     BOOST_ASSERT_MSG(boost::simd::assert_all(is_nltz(a0)),
                      "reallog cannot produce complex result.");
     return log(a0);
   }
 };
} } }


#endif
