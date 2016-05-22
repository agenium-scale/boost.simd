// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/scalar/sin.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct sin_scalar
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using ret_type = T;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x0) -> ret_type
         { return bs::sin(x0); }
       , nsb::generators::rand<T>(min0, max0)
       );
   }
};

template <typename T>
struct fast_sin_scalar
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using ret_type = T;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x0) -> ret_type
       { return bs::fast_(bs::sin)(x0); }
       , nsb::generators::rand<T>(min0, max0)
       );
   }
};

int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<sin_scalar, NS_BENCH_IEEE_TYPES>(-0.785398163397447, 0.785398163397447);
   nsb::make_for_each<sin_scalar, NS_BENCH_IEEE_TYPES>( -10,  10);
   nsb::make_for_each<fast_sin_scalar, NS_BENCH_IEEE_TYPES>(-0.785398163397447, 0.785398163397447);
   return 0;
}

