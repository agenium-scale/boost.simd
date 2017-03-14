// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor nthroot in scalar mode for double type with raw_.
#include <simd_bench.hpp>
#include <boost/simd/function/nthroot.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bd =  boost::dispatch;
namespace bs =  boost::simd;
struct nthr
{
  template<class T> T operator()(const T & a, const T & N) const
  {
    return bs::raw_(bs::nthroot)(a, bd::as_integer_t<T>(N));
  }
};
DEFINE_BENCH_MAIN()
{
  using T = double;
  run<T>(nthr(), nsbg::rand<T>(0, 10), nsbg::rand<T>(0, 10));
}
