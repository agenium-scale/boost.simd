//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/simd/splat.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<bs::logical<T>, N>;

  STF_TYPE_IS(p_t, decltype(bs::splat<p_t>(T())));
  STF_TYPE_IS(p_t, decltype(bs::splat<p_t>(true)));

  p_t ref;
  for(std::size_t i = 0; i < N; ++i) ref[i] = true;

  STF_EQUAL(bs::splat<p_t>(T(2)), ref);
  STF_EQUAL(bs::splat<p_t>(true), ref);

  for(std::size_t i = 0; i < N; ++i) ref[i] = false;
  STF_EQUAL(bs::splat<p_t>(T(0)) , ref);
  STF_EQUAL(bs::splat<p_t>(false), ref);
}

STF_CASE_TPL( "Check splat behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
