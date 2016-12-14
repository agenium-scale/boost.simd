// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor nthroot in simd mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/nthroot.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

template < int N>
struct nthr
{
  template<class T> T operator()(const T & a) const
  {
    using i_t = bd::as_integer_t<T>;
    return bs::nthroot(a, bs::enumerate<i_t>(N));
  }
};
DEFINE_SIMD_BENCH(simd_nthroot, nthr<10>());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_nthroot, double>(0, 10);
}
