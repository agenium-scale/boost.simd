// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/all.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct all_simd
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using pack_t = bs::pack<T>;
     using ret_type = bool;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0) -> ret_type
         { return bs::all(x0); }
       , nsb::generators::rand<pack_t>(min0, max0)
       );
   }
};

template <typename T>
struct all_simd_logical
{
   void operator()()
   {
     using pack_t = bs::pack<bs::logical<T>>;
     using ret_type = bool;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0) -> ret_type
         { return bs::all(x0); }
       , nsb::generators::randlg<pack_t>()
       );
   }
};

int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<all_simd, NS_BENCH_SIGNED_NUMERIC_TYPES>( -10,  10);
   nsb::make_for_each<all_simd, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0,  10);
   nsb::make_for_each<all_simd_logical, NS_BENCH_SIGNED_NUMERIC_TYPES>();
   return 0;
}

