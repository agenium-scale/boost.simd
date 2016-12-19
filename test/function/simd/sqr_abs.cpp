//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/sqr_abs.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i+1);
    b[i] = bs::sqr_abs(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::sqr_abs(aa1), bb);
}

STF_CASE_TPL("Check sqr_abs on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL (" sqr_abs real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr_abs;
  using p_t = bs::pack<T>;
  using r_t = decltype(sqr_abs(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, r_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(sqr_abs(bs::Inf<p_t>()), bs::Inf<p_t>());
  STF_EQUAL(sqr_abs(bs::Minf<p_t>()), bs::Inf<p_t>());
  STF_IEEE_EQUAL(sqr_abs(bs::Nan<p_t>()), bs::Nan<p_t>());
#endif
  STF_EQUAL(sqr_abs(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr_abs(bs::Mone<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr_abs(bs::Valmax<p_t>()), bs::Inf<p_t>());
  STF_EQUAL(sqr_abs(bs::Valmin<p_t>()), bs::Inf<p_t>());
  STF_EQUAL(sqr_abs(bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(sqr_abs(T(1)), T(1));
} // end of test for floating_

STF_CASE_TPL (" sqr_absunsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr_abs;
  using p_t = bs::pack<T>;
  using r_t = decltype(sqr_abs(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, r_t);

  // specific values tests
  STF_EQUAL(sqr_abs(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr_abs(bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" sqr_abs signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqr_abs;
  using p_t = bs::pack<T>;
  using r_t = decltype(sqr_abs(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, r_t);

  // specific values tests
  STF_EQUAL(sqr_abs(bs::Mone<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr_abs(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(sqr_abs(bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for signed_int_
