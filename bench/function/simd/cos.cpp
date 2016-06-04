// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/cos.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct cos_simd
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using pack_t = bs::pack<T>;
     using ret_type = bs::pack<T>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0) -> ret_type
       {
           return bs::cos(x0); }
       , nsb::generators::range<pack_t>(min0, max0)
       );
   }
};

template <typename T>
struct fast_cos_simd
{
   template <typename U>
   void operator()(U min1, U max1)
   {
     using pack_t = bs::pack<T>;
     using ret_type = bs::pack<T>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t& x ) -> ret_type
       { return bs::fast_(bs::cos)(x); }
       , nsb::generators::rand<pack_t>(min1, max1)
       );
   }


template <typename T>
struct small_cos_simd
{
   template <typename U>
   void operator()(U min1, U max1)
   {
     using  pack_t = bs::pack<T>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t& x ) -> pack_t
       { return bs::cos(x, bs::tag::clipped_small_); }
       , nsb::generators::range<pack_t>(min1, max1, 1)
       );
   }
};

int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<fast_cos_simd, NS_BENCH_IEEE_TYPES>(-0.5, 0.5);
   nsb::make_for_each<cos_simd, NS_BENCH_IEEE_TYPES>(-0.5, 0.5);
   nsb::make_for_each<cos_simd, NS_BENCH_IEEE_TYPES>(-0.7, 0.7);
   nsb::make_for_each<cos_simd, NS_BENCH_IEEE_TYPES>(-20, 20);
   nsb::make_for_each<cos_simd, NS_BENCH_IEEE_TYPES>(-60, 60);
   nsb::make_for_each<cos_simd, NS_BENCH_IEEE_TYPES>(-1000, 1000);
   nsb::make_for_each<small_cos_simd, NS_BENCH_IEEE_TYPES>(-3, 3);
   return 0;
}



