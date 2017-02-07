//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/two_split.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;


  T a1[N], r1[N], r2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     std::tie(r1[i], r2[i]) = bs::two_split(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t rr21, rr22;
  p_t rr1(&r1[0], &r1[0]+N);
  p_t rr2(&r2[0], &r2[0]+N);
  std::tie(rr21, rr22) = bs::two_split(aa1);
  STF_IEEE_EQUAL(rr21, rr1);
  STF_IEEE_EQUAL(rr22, rr2);
}

STF_CASE_TPL("Check two_split on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
