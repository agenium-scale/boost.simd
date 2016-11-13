//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/divides.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/zero.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(1+i) : T(3+i);
    a2[i] = (i%2) ? T(i+N) : T(2*i+1);
    b[i] = bs::divides(a1[i], a2[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::divides(aa1, aa2), bb, 0.5);
  STF_ULP_EQUAL(aa1/aa2, bb, 0.5);
}

STF_CASE_TPL("Check divides on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL("Check saturaetd divides on pack", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void tests(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    a2[i] = (i%2) ? T(i+N) : T(-(i+N));
    b[i] = bs::saturated_(bs::divides)(a1[i], a2[i]);
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::saturated_(bs::divides)(aa1, aa2), bb, 0.5);
}

STF_CASE_TPL("Check saturated divides on pack", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}


STF_CASE_TPL( "Check divides behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::divides;
  using p_t = bs::pack<T>;
  using r_t = decltype(divides(p_t(), p_t()));

  STF_TYPE_IS(r_t, p_t);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(divides(bs::Inf<p_t>(),  bs::Inf<p_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divides(bs::Minf<p_t>(), bs::Minf<p_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divides(bs::Nan<p_t>(),  bs::Nan<p_t>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(divides(p_t(1), p_t(0)), bs::Inf<r_t>());
  STF_IEEE_EQUAL(divides(p_t(0), p_t(0)), bs::Nan<r_t>());
  STF_EQUAL(divides(p_t(1), p_t(1)), bs::One<r_t>());
}

