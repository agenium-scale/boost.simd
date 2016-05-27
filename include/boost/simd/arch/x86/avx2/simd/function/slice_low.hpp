//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_SLICE_LOW_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_SLICE_LOW_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/meta/as_arithmetic.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/hierarchy.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  // -----------------------------------------------------------------------------------------------
  // slice_low pack of AVX2 integer
  BOOST_DISPATCH_OVERLOAD ( slice_low_
                          , (typename T)
                          , bs::avx2_
                          , bs::pack_< bd::integer_<T>, bs::avx_ >
                          )
  {
    static const std::size_t half = T::static_size/2;
    using result_t   = typename T::template resize<half>;

    BOOST_FORCEINLINE result_t operator()(T const& a0) const
    {
      return _mm256_extractf128_si256(a0, 0);
    }
  };
} } }

#endif
