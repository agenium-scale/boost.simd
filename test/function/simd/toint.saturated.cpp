//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/ldexp.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using iT = bd::as_integer_t<T>;
  using i_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::saturated_(bs::toint)(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  i_t bb (&b[0], &b[0]+N);
  STF_EQUAL(bs::saturated_(bs::toint)(aa1), bb);
}

STF_CASE_TPL("Check toint_s on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}



STF_CASE_TPL (" bs::saturated_(bs::toint) real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T>;
  using iT = bd::as_integer_t<T, signed>;
  using r_t = decltype(bs::saturated_(bs::toint)(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t, signed>));

  // specific values tests
  STF_EQUAL(bs::saturated_(bs::toint)(p_t(2)*bs::Valmax<p_t>()),  bs::Valmax<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(p_t(2)*bs::Valmin<p_t>()),  bs::Valmin<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(p_t(1.5)*bs::Valmax<p_t>()),  bs::Valmax<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(p_t(1.5)*bs::Valmin<p_t>()),  bs::Valmin<r_t>());


  STF_EQUAL(bs::saturated_(bs::toint)(bs::Inf<p_t>()),  bs::Inf<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::Minf<p_t>()), bs::Minf<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::Nan<p_t>()),  bs::Zero<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::One<p_t>()),  bs::One<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::Zero<p_t>()), bs::Zero<r_t>());

  p_t v = p_t(1);
  iT iv = 1;
  int N = sizeof(T)*8-1;
  for(int i=0; i < N ; i++, v*= p_t(2), iv <<= iT(1))
  {
    STF_EQUAL(bs::saturated_(bs::toint)(v), r_t(iv));
    STF_EQUAL(bs::saturated_(bs::toint)(-v), -r_t(iv));
  }
  STF_EQUAL(bs::saturated_(bs::toint)(bs::ldexp(bs::One<p_t>(), N)), bs::Valmax<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::ldexp(bs::One<p_t>(), N+1)), bs::Valmax<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(-bs::ldexp(bs::One<p_t>(), N+1)), bs::Valmin<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(-bs::ldexp(bs::One<p_t>(), N+1)), bs::Valmin<r_t>());

} // end of test for floating_

STF_CASE_TPL (" bs::saturated_(bs::toint) unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T>;
  using r_t = decltype(bs::saturated_(bs::toint)(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t, signed>));

  // specific values tests
  STF_EQUAL(bs::saturated_(bs::toint)(bs::One<p_t>()),  bs::One<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" bs::saturated_(bs::toint) signed",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T>;
  using r_t = decltype(bs::saturated_(bs::toint)(p_t()));
  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t, signed>));


  // specific values tests
  STF_EQUAL(bs::saturated_(bs::toint)(bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::One<p_t>()),  bs::One<r_t>());
  STF_EQUAL(bs::saturated_(bs::toint)(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for signed_int_
