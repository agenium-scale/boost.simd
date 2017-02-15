// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor any in scalar mode for std::int16_t type with no decorator (regular call).
#include <scalar_bench.hpp>
#include <boost/scalar/function/any.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::scalar;

DEFINE_SCALAR_BENCH(scalar_any, bs::any);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_any, std::int16_t>(-10, 10);
}
