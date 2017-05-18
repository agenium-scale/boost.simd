//==================================================================================================
/*!
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/raw.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N], a2[N], c[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = ((i%2) ? T(2*i) : T(-2*i))/T(3);
    a2[i] = T(2*i+1)/T(2);
    b[i] = bs::raw_(bs::nearbyint)(a1[i]) ;
    c[i] = bs::raw_(bs::nearbyint)(a2[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb (&b[0], &b[0]+N);
  p_t cc (&c[0], &c[0]+N);
  STF_IEEE_EQUAL(bs::raw_(bs::nearbyint)(aa1), bb);
  STF_IEEE_EQUAL(bs::raw_(bs::nearbyint)(aa2), cc);
}

STF_CASE_TPL("Check raw_(nearbyint) on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
