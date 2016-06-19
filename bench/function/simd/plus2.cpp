// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct plus_simd : nsb::experiment
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     using pack_t = bs::pack<T>;
     run_bench<pack_t::static_size>
       ( bs::plus
       , nsb::generators::rand<pack_t>(min0, max0)
       , nsb::generators::rand<pack_t>(min1, max1)
       );
   }
};

template <typename T>
struct scalar_plus_simd : nsb::experiment
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     run_bench<1>
       ( "scalar_plus_simd", // We force the name here
       , [](T x0, T x1) { return x0 + x1; }
       , nsb::generators::rand<T>(min0, max0)
       , nsb::generators::rand<T>(min1, max1)
       );
   }
};

int main(int argc, char** argv) {
   nsb::parse_args(argc, argv);
   nsb::for_each<plus_simd, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10, -10, 10);
   nsb::for_each<plus_simd, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10,  0,  10);
   nsb::for_each<scalar_plus_simd, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10, -10, 10);
   nsb::for_each<scalar_plus_simd, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10,  0,  10);
   print_results();
   return 0;
}

