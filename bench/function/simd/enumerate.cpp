// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/enumerate.hpp>
#include <boost/simd/pack.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct enumer
{
  template<class T> bs::pack<T> operator()(const T & a) const
  {
    return bs::enumerate<bs::pack<T>>(a);
  }
};

DEFINE_SCALAR_BENCH(simd_enumerate,enumer());


DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_enumerate, NS_BENCH_IEEE_TYPES>(-10, 10);
}
