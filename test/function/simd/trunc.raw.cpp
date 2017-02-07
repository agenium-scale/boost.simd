//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, int N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a[N], b[N];

  for(int i = 0; i < N; ++i)
  {
    a[i] = ((i%2) ? T(i*2) : T(-2*i))/T(3);
    b[i] = bs::raw_(bs::trunc)(a[i]) ;
  }

  p_t aa(&a[0], &a[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_IEEE_EQUAL(bs::raw_(bs::trunc)(aa), bb);
}

STF_CASE_TPL("Check raw(trunc) behavior on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

STF_CASE_TPL( "Check return type from raw(trunc)", STF_NUMERIC_TYPES)
{
  using bs::trunc;
  STF_TYPE_IS(decltype(bs::raw_(bs::trunc)(bs::pack<T>())), bs::pack<T>);
}
