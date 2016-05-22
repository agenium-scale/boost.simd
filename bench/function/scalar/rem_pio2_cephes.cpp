// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/scalar/rem_pio2_cephes.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>
#include <tuple>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace nsb = ns::bench;

template <typename T>
struct rem_pio2_cephes_scalar
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using iT = bd::as_integer_t<T>;
     using ret_type = std::pair<iT, T>;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x0) -> ret_type
         { return bs::rem_pio2_cephes(x0); }
       , nsb::generators::rand<T>(min0, max0)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<rem_pio2_cephes_scalar, NS_BENCH_IEEE_TYPES>( -10,  10);
   return 0;
}

