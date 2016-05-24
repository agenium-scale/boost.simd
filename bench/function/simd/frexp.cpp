// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/simd/frexp.hpp>
#include <boost/simd/pack.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>
#include <tuple>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace nsb = ns::bench;

template <typename T>
struct frexp_simd
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using pack_t = bs::pack<T>;
     using ipack_t = bs::pack<bd::as_integer_t<T>>;
     using ret_type = std::pair<pack_t, ipack_t>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0) -> ret_type
         { return bs::frexp(x0); }
       , nsb::generators::rand<pack_t>(min0, max0)
       );
   }
};

template <typename T>
struct fast_frexp_simd
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using pack_t = bs::pack<T>;
     using ipack_t = bs::pack<bd::as_integer_t<T>>;
     using ret_type = std::pair<pack_t, ipack_t>;
     nsb::make_function_experiment_cpe_sized_<pack_t::static_size>
       ( [](const pack_t & x0) -> ret_type
       { return bs::fast_(bs::frexp)(x0); }
       , nsb::generators::rand<pack_t>(min0, max0)
       );
   }
};

int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<frexp_simd, NS_BENCH_IEEE_TYPES>( -10,  10);
   nsb::make_for_each<fast_frexp_simd, NS_BENCH_IEEE_TYPES>( -10,  10);
   return 0;
}

