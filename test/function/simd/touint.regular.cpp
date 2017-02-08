//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/touint.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using iT = bd::as_integer_t<T, unsigned>;
  using i_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] =  T(i);
    b[i]  = iT(i);
  }
  p_t aa1(&a1[0], &a1[0]+N);
  i_t bb (&b[0], &b[0]+N);
  STF_EQUAL(bs::touint(aa1), bb);
}

STF_CASE_TPL("Check touint on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
