// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/pack.hpp>
#include <boost/dispatch/meta/downgrade.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace nsb = ns::bench;

template <typename T>
struct group_simd
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     using pack_t = bs::pack<T>;
     using ret_type =  bs::pack<bd::downgrade_t<T>>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0, const pack_t & x1) -> ret_type
         { return bs::group(x0, x1); }
       , nsb::generators::rand<pack_t>(min0, max0)
       , nsb::generators::rand<pack_t>(min1, max1)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<group_simd, double, std::int64_t, std::int32_t, std::int16_t>( -10,  10,  -10,  10);
   nsb::make_for_each<group_simd, std::uint64_t, std::uint32_t, std::uint16_t>(0,  10, 0,  10);
//    nsb::make_for_each<group_simd, NS_BENCH_SIGNED_NUMERIC_TYPES>( -10,  10,  -10,  10);
//    nsb::make_for_each<group_simd, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0,  10, 0,  10);
   return 0;
}

