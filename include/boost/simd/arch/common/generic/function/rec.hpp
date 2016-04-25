//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/function/rec.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( rec_
                          , (typename T)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::generic_<bd::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(const fast_tag &, T const& a
                                  ) const BOOST_NOEXCEPT
    {
      return rec(a);
    }
  };
} } }

#endif
