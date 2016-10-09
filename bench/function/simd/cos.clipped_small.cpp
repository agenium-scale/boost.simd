// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/cos.hpp>
#include <boost/simd/pack.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct gen
{
  template<class T> T operator()(const T & a) const
  {
    namespace bst = bs::tag;
    return bs::cos(a, bst::clipped_small_);
  }
};

DEFINE_SIMD_BENCH(simd_cos_clipped_small, gen());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_cos_clipped_small, NS_BENCH_IEEE_TYPES>(-10, 10);
}
