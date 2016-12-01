// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/ldexp.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

DEFINE_SIMD_BENCH(simd_ldexp, bs::ldexp);


template < int N >
struct ldep
{
  template<class T> T operator()(const T & a) const
  {
    return bs::pedantic_(bs::ldexp)(a, T(N));
  }
};

  DEFINE_SIMD_BENCH(pedantic_simd_lde10, ldep<10>());

DEFINE_BENCH_MAIN() {
  nsb::for_each<simd_lde10, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<pedantic_simd_lde10, NS_BENCH_IEEE_TYPES>(-10, 10);
}


