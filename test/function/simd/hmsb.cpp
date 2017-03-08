//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/hmsb.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T,int N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a[N];
  bs::bitset<N> r;
  r.reset();

  for(int i = 0; i < N; ++i)
  {
    a[i] = (i%2) ? T(i) : T(-i);
    r.set(i,bs::bitwise_and(bs::Signmask<bd::as_integer_t<T>>(), a[i]) != 0);
  }

  p_t aa(&a[0], &a[0]+N);
  STF_EQUAL(bs::hmsb(aa), r);
}

STF_CASE_TPL("Check hmsb on pack", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
