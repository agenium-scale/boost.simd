// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/is_nlt.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct is_nlt_simd
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
         { return bs::is_nlt(x0, x1); }
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<is_nlt_simd, NS_BENCH_SIGNED_NUMERIC_TYPES>( -10,  10,  -10,  10);
   nsb::make_for_each<is_nlt_simd, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0,  10, 0,  10);
   return 0;
}

