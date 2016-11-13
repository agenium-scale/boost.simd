//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/three.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = ((i%2) ? T(i*2) : T(-2*i))/T(3);
    b[i] = bs::trunc(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::trunc(aa1), bb);
}

STF_CASE_TPL("Check trunc on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}



STF_CASE_TPL (" trunc real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::trunc;
  using p_t = bs::pack<T>;
  using r_t = decltype(trunc(p_t()));

  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(trunc(bs::Inf<p_t>()), bs::Inf<p_t>());
  STF_EQUAL(trunc(bs::Minf<p_t>()), bs::Minf<p_t>());
  STF_IEEE_EQUAL(trunc(bs::Nan<p_t>()), bs::Nan<p_t>());
#endif
  STF_EQUAL(trunc(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(trunc(bs::Mone<p_t>()), bs::Mone<p_t>());
  STF_EQUAL(trunc(bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(trunc(bs::Pi<p_t>()), bs::Three<p_t>());
  STF_EQUAL(trunc(p_t(1.4)), p_t(1));
  STF_EQUAL(trunc(p_t(1.5)), p_t(1));
  STF_EQUAL(trunc(p_t(1.6)), p_t(1));
  STF_EQUAL(trunc(p_t(2.5)), p_t(2));
  STF_EQUAL(trunc(p_t(-1.4)), p_t(-1));
  STF_EQUAL(trunc(p_t(-1.5)), p_t(-1));
  STF_EQUAL(trunc(p_t(-1.6)), p_t(-1));
  STF_EQUAL(trunc(p_t(-2.5)), p_t(-2));
} // end of test for floating_

STF_CASE_TPL (" trunc unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::trunc;
  using p_t = bs::pack<T>;
  using r_t = decltype(trunc(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(trunc(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(trunc(bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" trunc signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::trunc;
  using p_t = bs::pack<T>;
  using r_t = decltype(trunc(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(trunc(bs::Mone<p_t>()), bs::Mone<p_t>());
  STF_EQUAL(trunc(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(trunc(bs::Zero<p_t>()), bs::Zero<p_t>());
} // end of test for signed_int_

STF_CASE_TPL ( "fast trunc real",  STF_IEEE_TYPES)
{

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::trunc;
  using p_t = bs::pack<T>;
  using r_t = decltype(trunc(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(bs::fast_(trunc)(bs::One<p_t>()), bs::One<p_t>());
  STF_EQUAL(bs::fast_(trunc)(bs::Mone<p_t>()), bs::Mone<p_t>());
  STF_EQUAL(bs::fast_(trunc)(bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(bs::fast_(trunc)(bs::Pi<p_t>()), bs::Three<p_t>());
  STF_EQUAL(bs::fast_(trunc)(p_t(1.4)), p_t(1));
  STF_EQUAL(bs::fast_(trunc)(p_t(1.5)), p_t(1));
  STF_EQUAL(bs::fast_(trunc)(p_t(1.6)), p_t(1));
  STF_EQUAL(bs::fast_(trunc)(p_t(2.5)), p_t(2));
  STF_EQUAL(bs::fast_(trunc)(p_t(-1.4)), p_t(-1));
  STF_EQUAL(bs::fast_(trunc)(p_t(-1.5)), p_t(-1));
  STF_EQUAL(bs::fast_(trunc)(p_t(-1.6)), p_t(-1));
  STF_EQUAL(bs::fast_(trunc)(p_t(-2.5)), p_t(-2));
} // end of test for floating_

