// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/is_less_equal.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct is_less_equal_simd
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     using pack_t = bs::pack<T>;
     using ret_type = bs::pack<bs::logical<T>>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0, const pack_t & x1) -> ret_type
         { return bs::is_less_equal(x0, x1); }
       , nsb::generators::rand<pack_t>(min0, max0)
       , nsb::generators::rand<pack_t>(min1, max1)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<is_less_equal_simd, NS_BENCH_SIGNED_NUMERIC_TYPES>( -10,  10,  -10,  10);
   nsb::make_for_each<is_less_equal_simd, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0,  10, 0,  10);
   return 0;
}

