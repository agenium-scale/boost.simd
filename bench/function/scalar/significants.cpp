// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/scalar/significants.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace nsb = ns::bench;

template <typename T>
struct significants_scalar
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     using iT = bd::as_integer_t<T>;
     using ret_type = T;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x0, const iT & x1) -> ret_type
         { return bs::significants(x0, x1); }
       , nsb::generators::rand<T>(min0, max0)
       , nsb::generators::rand<iT>(min1, max1)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<significants_scalar, NS_BENCH_IEEE_TYPES>( -10,  10, 1, 5);
   return 0;
}

