//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test_fast(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] =  T(N-i);
    b[i] = bs::fast_(bs::sqrt)(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::fast_(bs::sqrt)(aa1), bb, 2048);
}

STF_CASE_TPL("Check fast(sqrt) on pack", STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_fast<T, N>($);
  test_fast<T, N/2>($);
  test_fast<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  a1[0] = bs::Inf<T>();
  b[0] = bs::sqrt(a1[0]);

  for(std::size_t i = 1; i < N; ++i)
  {
    a1[i] =  T(N-i);
    b[i] = bs::sqrt(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::sqrt(aa1), bb, 0.5);
}

STF_CASE_TPL("Check sqrt on pack", STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" sqrt real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt;
  using p_t = bs::pack<T>;
  using r_t = decltype(sqrt(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, r_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sqrt(bs::Inf<p_t>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Minf<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(sqrt(bs::Mone<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::One<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Two<p_t>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sqrt(bs::Zero<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Mzero<p_t>()), bs::Mzero<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Four<p_t>()), bs::Two<r_t>(), 0);
  STF_EQUAL(bs::is_negative(sqrt(bs::Mzero<p_t>())), bs::True<p_t>());
  STF_EQUAL(bs::is_positive(sqrt(bs::Zero<p_t>())) , bs::True<p_t>());
} // end of test for floating_

STF_CASE_TPL (" sqrt si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt;
  using p_t = bs::pack<T>;
  using r_t = decltype(sqrt(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, r_t);

  // specific values tests
  STF_EQUAL(sqrt(bs::Zero<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(sqrt(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(sqrt(bs::Two<p_t>()), bs::One<r_t>());
  STF_EQUAL(sqrt(bs::Zero<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(sqrt(bs::Four<p_t>()), bs::Two<r_t>());
} // end of test for floating_

STF_CASE_TPL (" sqrt ui",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T>;
  using bs::sqrt;

  using r_t = decltype(sqrt(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, r_t);

  // specific values tests
 for(int i=0; i <255 ; i++)
 {
   STF_EQUAL(sqrt(p_t(i)), r_t(sqrt(double(i))));
 }
} // end of test for floating_
