// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor significants in scalar mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/significants.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;
struct signif
{
  template<class T> T operator()(const T & a, const T & N) const
  {
    using i_t = bd::as_integer_t<T>;
    return bs::significants(a, i_t(N));
  }
};

DEFINE_BENCH_MAIN()
{
  using T = double;
  run<T>(signif(), nsbg::rand<T>(0, 10), nsbg::rand<T>(0, 10));
}
