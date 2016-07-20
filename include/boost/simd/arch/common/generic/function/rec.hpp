//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/raw.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( rec_
                          , (typename T)
                          , bd::cpu_
                          , bs::fast_tag
                          , bd::generic_<bd::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(const fast_tag &, T const& a) const BOOST_NOEXCEPT
    {
      return rec(a);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rec_
                          , (typename T)
                          , bd::cpu_
                          , bs::raw_tag
                          , bd::generic_<bd::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(const raw_tag &, T const& a) const BOOST_NOEXCEPT
    {
      return rec(a);
    }
  };
} } }

#endif
