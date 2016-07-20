// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/scalar/tenpower.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace nsb = ns::bench;

template <typename T>
struct tenpower_scalar
{
   template <typename U>
   void operator()(U min0, U max0)
   {
     using ret_type = bd::as_floating_t<T>;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x0) -> ret_type
         { return bs::tenpower(x0); }
       , nsb::generators::rand<T>(min0, max0)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<tenpower_scalar, std::int32_t, std::int64_t>( -10,  10);
   nsb::make_for_each<tenpower_scalar, std::uint32_t, std:: uint64_t>(0,  10);
   return 0;
}

