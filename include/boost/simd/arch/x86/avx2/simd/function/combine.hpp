//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_COMBINE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_COMBINE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/meta/as_arithmetic.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  // -----------------------------------------------------------------------------------------------
  // combine pack of AVX integers
  BOOST_DISPATCH_OVERLOAD ( combine_
                          , (typename T)
                          , bs::avx2_
                          , bs::pack_< bd::integer_<T>, bs::sse_ >
                          , bs::pack_< bd::integer_<T>, bs::sse_ >
                          )
  {
    using result_t = typename T::template resize<2 * T::static_size>;

    BOOST_FORCEINLINE result_t operator()(T const& a0, T const& a1) const
    {
      result_t  that = _mm256_castsi128_si256(a0);
      return _mm256_inserti128_si256(that, a1, 1);
    }
  };
} } }

#endif
