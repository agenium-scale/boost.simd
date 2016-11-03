//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

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

STF_CASE_TPL("Check saturated divides on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" bs::saturated_(divides) signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divides;
  using p_t = bs::pack<T>;

  // return type conformity test
  STF_EXPR_IS(bs::saturated_(divides)(p_t(), p_t()), p_t);

  // specific values tests
  STF_EQUAL(bs::saturated_(divides)(bs::Mone<p_t>(), bs::Mone<p_t>()), bs::One<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::One<p_t>(), bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<p_t>(),bs::Mone<p_t>()), bs::Valmin<p_t>()+bs::One<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<p_t>(),bs::One<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmin<p_t>(),bs::Mone<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Mone<p_t>(), bs::Zero<p_t>()), bs::Valmin<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Mtwo<p_t>(), bs::Zero<p_t>()), bs::Valmin<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmin<p_t>(), bs::Zero<p_t>()), bs::Valmin<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::One<p_t>(), bs::Zero<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Two<p_t>(), bs::Zero<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<p_t>(), bs::Zero<p_t>()), bs::Valmax<p_t>());
} // end of test for signed_int_


STF_CASE_TPL (" bs::saturated_(divides) unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::divides;
  using p_t = bs::pack<T>;

  // return type conformity test
  STF_EXPR_IS(bs::saturated_(divides)(p_t(), p_t()), p_t);

  // specific values tests
  STF_EQUAL(bs::saturated_(divides)(bs::One<p_t>(), bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<p_t>(),bs::One<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::One<p_t>(), bs::Zero<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Two<p_t>(), bs::Zero<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(divides)(bs::Valmax<p_t>(), bs::Zero<p_t>()), bs::Valmax<p_t>());
} // end of test for unsigned_int_
