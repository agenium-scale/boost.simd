// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/exp.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct exp_packed
{
   template <typename U>
   void operator()(U min1, U max1)
   {
     using  T = T;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T& x ) -> T
       { return bs::exp(x); }
       , nsb::generators::rand<T>(min1, max1)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<exp_packed, NS_BENCH_IEEE_TYPES>(-0.5, 0.5);
   nsb::make_for_each<exp_packed, NS_BENCH_IEEE_TYPES>(-10, 20);
   nsb::make_for_each<exp_packed, NS_BENCH_IEEE_TYPES>(-20, 20);
   nsb::make_for_each<exp_packed, NS_BENCH_IEEE_TYPES>(-60, 60);
   nsb::make_for_each<exp_packed, NS_BENCH_IEEE_TYPES>(-1000, 1000);
   return 0;
}

