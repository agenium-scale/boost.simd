//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i+1) : T(N+i+1);
    b[i] = bs::sqr(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_EQUAL(bs::sqr(aa1), bb);
}

STF_CASE_TPL("Check sqr on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void tests(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::saturated_(bs::sqr)(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_EQUAL(bs::saturated_(bs::sqr)(aa1), bb);
}

STF_CASE_TPL("Check saturated sqr on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}


STF_CASE_TPL (" sqr real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr;
  using p_t = bs::pack<T>;
  using r_t = decltype(sqr(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(sqr(bs::Inf<p_t>()), bs::Inf<p_t>());
  STF_EQUAL(sqr(bs::Minf<p_t>()), bs::Inf<p_t>());
  STF_IEEE_EQUAL(sqr(bs::Nan<p_t>()), bs::Nan<p_t>());
#endif
  STF_EQUAL(sqr(bs::Mone<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr(bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for floating_

STF_CASE_TPL (" sqr unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr;
  using p_t = bs::pack<T>;
  using r_t = decltype(sqr(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(sqr(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr(bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" sqr signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr;
  using p_t = bs::pack<T>;
  using r_t = decltype(sqr(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(sqr(bs::Mone<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr(bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for signed_int_

