// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/ifnot_minus.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct ifnot_minus_simd
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1, U min2, U max2)
   {
     using pack_t = bs::pack<T>;
     using ret_type = bs::pack<T>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0, const pack_t & x1, const pack_t & x2) -> ret_type
         { return bs::ifnot_minus(x0, x1, x2); }
       , nsb::generators::rand<pack_t>(min0, max0)
       , nsb::generators::rand<pack_t>(min1, max1)
       , nsb::generators::rand<pack_t>(min2, max2)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<ifnot_minus_simd, NS_BENCH_SIGNED_NUMERIC_TYPES>( -10,  10,  -10,  10,  -10,  10);
   nsb::make_for_each<ifnot_minus_simd, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0,  10, 0,  10, 0,  10);
   return 0;
}

