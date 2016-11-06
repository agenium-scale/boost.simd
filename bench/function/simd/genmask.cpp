// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/pack.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct gen
{
  template<class T> T operator()(const T & a) const
  {
    return bs::genmask(a);
  }
};
DEFINE_SIMD_BENCH(simd_genmask, gen());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_genmask, NS_BENCH_IEEE_TYPES>(-10, 10);
}
