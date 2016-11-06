//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = 1/a1[i];
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::rec(aa1), bb, 0.5);
}

STF_CASE_TPL("Check rec on pack", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test_fast(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i+1) : T(-i-1);
    b[i] = T(1)/a1[i];
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::fast_(bs::rec)(aa1), bb, 16);
}

STF_CASE_TPL("Check fast(rec) on pack", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test_fast<T, N>($);
  test_fast<T, N/2>($);
  test_fast<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test_raw(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N-1; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);
    b[i] = T(1)/a1[i];
  }

  a1[N-1] = 1e5;
  b[N-1] = T(1)/a1[N-1];

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_RELATIVE_EQUAL(bs::raw_(bs::rec)(aa1), bb, 1);
}

STF_CASE_TPL("Check raw(rec) on pack", STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test_raw<T, N>($);
  test_raw<T, N/2>($);
  test_raw<T, N*2>($);
}

STF_CASE_TPL("regular rec",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rec;
  using p_t = bs::pack<T>;

  // return type conformity test
  STF_EXPR_IS( rec(p_t()) , p_t );

  // specific values tests
  STF_EQUAL(rec(bs::Inf<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(rec(bs::Minf<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(rec(bs::Mone<p_t>()), bs::Mone<p_t>());
  STF_EQUAL(rec(bs::Mzero<p_t>()), bs::Minf<p_t>());
  STF_IEEE_EQUAL(rec(bs::Nan<p_t>()), bs::Nan<p_t>());
  STF_EQUAL(rec(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(rec(bs::Zero<p_t>()), bs::Inf<p_t>());
} // end of test for floating_

