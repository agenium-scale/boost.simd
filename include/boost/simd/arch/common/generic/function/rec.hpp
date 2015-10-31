//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/function/rec.hpp>
#include <boost/simd/options.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( rec_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::unspecified_<T>>
                          , boost::simd::fast_tag
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a
                                  , fast_tag const& ) const BOOST_NOEXCEPT
    {
      return rec(a);
    }
  };
} } }

#endif
