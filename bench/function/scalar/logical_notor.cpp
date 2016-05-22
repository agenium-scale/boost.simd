// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/scalar/logical_notor.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct logical_notor_scalar
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     using ret_type = bs::logical<T>;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x0, const T & x1) -> ret_type
         { return bs::logical_notor(x0, x1); }
       , nsb::generators::rand<T>(min0, max0)
       , nsb::generators::rand<T>(min1, max1)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<logical_notor_scalar, NS_BENCH_SIGNED_NUMERIC_TYPES>( -10,  10,  -10,  10);
   nsb::make_for_each<logical_notor_scalar, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0,  10, 0,  10);
   return 0;
}

