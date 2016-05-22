// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/bitfloating.hpp>
#include <boost/simd/pack.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace nsb = ns::bench;

template <typename T>
struct bitfloating_simd
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using pack_t = bs::pack<T>;
     using ret_type = bs::pack<bd::as_floating_t<T>>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0) -> ret_type
         { return bs::bitfloating(x0); }
       , nsb::generators::rand<pack_t>(min0, max0)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<bitfloating_simd, std::int32_t, std::int64_t>( -10,  10);
   nsb::make_for_each<bitfloating_simd, std::uint32_t, std::uint64_t>(0,  10);
   return 0;
}

