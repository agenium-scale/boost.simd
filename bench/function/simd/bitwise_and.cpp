// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/sin.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

template <typename T>
struct bitwise_and_packed
{
   template <typename U>
   void operator()(U min1, U max1)
   {
     using  pack_t = bs::pack<T>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t& x, const pack_t& y ) -> pack_t
         { return bs::bitwise_and(x, y); }
       , nsb::generators::rand<pack_t>(min1, max1)
       , nsb::generators::rand<pack_t>(min1, max1)
       );
   }
};

template <typename T>
struct bitwise_and_scalar
{
   template <typename U>
   void operator()(U min1, U max1)
   {
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x, const T & y) -> T
         { return bs::bitwise_and(x, y); }
       , nsb::generators::rand<T>(min1, max1)
       , nsb::generators::rand<T>(min1, max1)
       );
   }
};

template <typename T>
struct bitwise_and_std
{
   template <typename U>
   void operator()(U min1, U max1)
   {
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x, const T & y) -> T
         { return x & y; }
       , nsb::generators::rand<T>(min1, max1)
       , nsb::generators::rand<T>(min1, max1)
       );
   }
};

int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);

   nsb::make_for_each<bitwise_and_packed, uint64_t>(0, 20);
   nsb::make_for_each<bitwise_and_packed, NS_BENCH_NUMERIC_TYPES>(-10, 10);
   nsb::make_for_each<bitwise_and_scalar, NS_BENCH_NUMERIC_TYPES>(-10, 10);
   nsb::make_for_each<bitwise_and_std,    NS_BENCH_INTEGRAL_TYPES>(-10, 10);

   return 0;
}

