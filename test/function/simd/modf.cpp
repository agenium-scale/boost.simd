//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/modf.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;

  T a1[N], ent[N], frac[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     std::tie(ent[i], frac[i]) = bs::modf(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t ment(&ent[0], &ent[0]+N);
  p_t efrac(&frac[0], &frac[0]+N);
  p_t ment1, efrac1;

  std::tie(ment1, efrac1) = bs::modf(aa1);

  STF_IEEE_EQUAL(ment1, ment);
  STF_IEEE_EQUAL(efrac1, efrac);
}

STF_CASE_TPL("Check modf on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
