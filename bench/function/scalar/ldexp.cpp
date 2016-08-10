// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/ldexp.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

DEFINE_SCALAR_BENCH(scalar_ldexp, bs::ldexp);

template < int N >
struct lde
{
  template<class T> T operator()(const T & a) const
  {
    return bs::ldexp(a, bd::as_integer_t<T>(N));
  }
};

  DEFINE_SCALAR_BENCH(scalar_lde10, lde<10>());
  DEFINE_SCALAR_BENCH(scalar_ldem10, lde<-10>());

DEFINE_BENCH_MAIN() {
  nsb::for_each<scalar_lde10, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<scalar_ldem10, NS_BENCH_IEEE_TYPES>(-10, 10);
}


