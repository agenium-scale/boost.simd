// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/two_prod.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>
#include <tuple>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct two_prod_simd
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     using pack_t = bs::pack<T>;
     using ret_type = std::pair<pack_t, pack_t>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0, const pack_t & x1) -> ret_type
         { return bs::two_prod(x0, x1); }
       , nsb::generators::rand<pack_t>(min0, max0)
       , nsb::generators::rand<pack_t>(min1, max1)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<two_prod_simd, NS_BENCH_IEEE_TYPES>( -10,  10,  -10,  10);
   return 0;
}

