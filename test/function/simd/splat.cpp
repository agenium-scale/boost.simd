//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/splat.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  STF_TYPE_IS(p_t, decltype(bs::splat<p_t>(T())));
  STF_TYPE_IS(p_t, decltype(bs::splat<p_t>(int())));

  T a1[N];
  for(std::size_t i = 0; i < N; ++i) a1[i] = T(27);
  p_t aa1(&a1[0], &a1[N]);
  STF_IEEE_EQUAL(bs::splat<p_t>(27), aa1);
  STF_IEEE_EQUAL(bs::splat<p_t>(T(27)), aa1);
}

STF_CASE_TPL( "Check splat behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = p_t::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
