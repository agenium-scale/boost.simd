// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

struct bcasti
{
  template<class T> bd::as_integer_t<T, unsigned> operator()(const T & a) const
  {
    return bs::bitwise_cast<bd::as_integer_t<T, unsigned>>(a);
  }
};

struct bcastf
{
  template<class T> bd::as_floating_t<T> operator()(const T & a) const
  {
    return bs::bitwise_cast<bd::as_floating_t<T>>(a);
  }
};

DEFINE_SCALAR_BENCH(scalar_bitwise_casti, bcasti());
DEFINE_SCALAR_BENCH(scalar_bitwise_castf, bcastf());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_bitwise_castf, int32_t, int64_t, uint32_t, uint64_t>(-10, 10);
  nsb::for_each<scalar_bitwise_casti, NS_BENCH_IEEE_TYPES>(-10, 10);
}
