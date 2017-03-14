// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor shift_right in scalar mode for float type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;
struct shr
{
  template<class T> T operator()(const T & a, const T & N) const
  {
    return bs::shift_right(a, bd::as_integer_t<T>(N));
  }
};

DEFINE_BENCH_MAIN()
{
  using T = float;
  run<T>(shr(), nsbg::rand<T>(-10, 10), nsbg::rand<T>(0, 31));
}
