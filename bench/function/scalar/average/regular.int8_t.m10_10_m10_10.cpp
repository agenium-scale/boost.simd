// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor average in scalar mode for std::int8_t type with no decorator (regular call).
#include <scalar_bench.hpp>
#include <boost/scalar/function/average.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::scalar;

DEFINE_SCALAR_BENCH(scalar_average, bs::average);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_average, std::int8_t>(-10, 10,-10, 10);
}
