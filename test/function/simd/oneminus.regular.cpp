//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::oneminus(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_EQUAL(bs::oneminus(aa1), bb);
}

STF_CASE_TPL("Check oneminus saturated on pack" , STF_NUMERIC_TYPES)
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
    b[i] = bs::saturated_(bs::oneminus)(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_EQUAL(bs::saturated_(bs::oneminus)(aa1), bb);
}

STF_CASE_TPL("Check oneminus on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}



STF_CASE_TPL (" oneminus signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus;
  using p_t = bs::pack<T>;
  using r_t = decltype(oneminus(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(oneminus(bs::Mone<p_t>()), bs::Two<p_t>());
  STF_EQUAL(oneminus(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(oneminus(bs::Valmax<p_t>()), bs::Valmin<p_t>()+bs::Two<p_t>());
  STF_EQUAL(oneminus(bs::Zero<p_t>()), bs::One<p_t>());
}

STF_CASE_TPL (" oneminus unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus;
  using p_t = bs::pack<T>;
  using r_t = decltype(oneminus(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(oneminus(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(oneminus(bs::Two<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(oneminus(bs::Zero<p_t>()), bs::One<p_t>());
}

STF_CASE_TPL(" oneminus floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::oneminus;
  using p_t = bs::pack<T>;
  using r_t = decltype(oneminus(p_t()));

  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(oneminus(bs::Inf<p_t>()), bs::Minf<p_t>());
  STF_IEEE_EQUAL(oneminus(bs::Nan<p_t>()), bs::Nan<p_t>());
  STF_EQUAL(oneminus(bs::Minf<p_t>()), bs::Inf<p_t>());
#endif
  STF_EQUAL(oneminus(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(oneminus(bs::Two<p_t>()), bs::Mone<p_t>());
  STF_EQUAL(oneminus(bs::Zero<p_t>()), bs::One<p_t>());
}

