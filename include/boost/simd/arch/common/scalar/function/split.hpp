//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SPLIT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SPLIT_HPP_INCLUDED

#include <boost/dispatch/meta/upgrade.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( split_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_<bd::unspecified_<A0> >
                          )
  {
    using result_t = bd::upgrade_t<A0>;
    BOOST_FORCEINLINE result_t  operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return result_t(a0);
    }
  };
} } }


#endif
