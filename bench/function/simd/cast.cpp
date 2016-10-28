// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/cast.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/pack.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

template<int N>
struct caster
{
  template<class T> bs::pack<float, N> operator()(const bs::pack<T, N> & a) const
  {
    return bs::cast<float>(a);
  }
};

DEFINE_SIMD_BENCH(simd_caster, caster<bs::pack<float>::static_size>());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_caster, /*int8_t, uint8_t, uint16_t, uint16_t, int32_t, uint32_t, int64_t, uint64_t,*/ float/*, double*/>(-10, 10);
}
