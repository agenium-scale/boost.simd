// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/scalar/split_multiplies.hpp>
#include <boost/dispatch/meta/upgrade.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace nsb = ns::bench;

template <typename T>
struct split_multiplies_scalar
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     using uT =  bs::pack<bd::upgrade_t<T>>;
     using ret_type =std::pair<uT, uT>;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x0, const T & x1) -> ret_type
         { return bs::split_multiplies(x0, x1); }
       , nsb::generators::rand<T>(min0, max0)
       , nsb::generators::rand<T>(min1, max1)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<split_multiplies_scalar, float, std::int8_t, std::int16_t, std::int32_t >( -10,  10,  -10,  10);
   nsb::make_for_each<split_multiplies_scalar, std::uint8_t, std::uint16_t, std::uint32_t>(0,  10, 0,  10);
   return 0;
}

