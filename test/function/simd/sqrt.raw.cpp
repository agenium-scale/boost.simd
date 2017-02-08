//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
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
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  a1[0] = bs::Inf<T>();
  b[0] = bs::raw_(bs::sqrt)(a1[0]);

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] =  T(N-i+1);
    b[i] = bs::raw_(bs::sqrt)(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_RELATIVE_EQUAL(bs::raw_(bs::sqrt)(aa1), bb, 0.5);
}

STF_CASE_TPL("Check sqrt on pack", STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
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
  STF_RELATIVE_EQUAL(bs::raw_(bs::sqrt)(bs::Mone<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(bs::sqrt)(bs::One<p_t>()), bs::One<r_t>(), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(bs::sqrt)(bs::Two<p_t>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(bs::sqrt)(bs::Zero<p_t>()), bs::Zero<r_t>(), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(bs::sqrt)(bs::Mzero<p_t>()), bs::Mzero<r_t>(), 0.5);
  STF_RELATIVE_EQUAL(bs::raw_(bs::sqrt)(bs::Four<p_t>()), bs::Two<r_t>(), 0.5);
} // end of test for floating_

