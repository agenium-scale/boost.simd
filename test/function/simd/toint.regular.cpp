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
    a1[i] = T(i)/N;
    b[i] = bs::toint(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  i_t bb (&b[0], &b[0]+N);
  STF_EQUAL(bs::toint(aa1), bb);
}

STF_CASE_TPL("Check toint on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}



STF_CASE_TPL (" toint real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint;
  using p_t = bs::pack<T>;
  using r_t = decltype(toint(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t, signed>));

  // specific values tests
  STF_EQUAL(toint(p_t(0.4)), r_t(0));
  STF_EQUAL(toint(p_t(0.5)), r_t(0));
  STF_EQUAL(toint(p_t(0.6)), r_t(0));
  STF_EQUAL(toint(bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(toint(bs::One<p_t>()),  bs::One<r_t>());
  STF_EQUAL(toint(bs::Zero<p_t>()), bs::Zero<r_t>());

} // end of test for floating_

STF_CASE_TPL (" toint unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint;
  using p_t = bs::pack<T>;
  using r_t = decltype(toint(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t, signed>));

  // specific values tests
  STF_EQUAL(toint(bs::One<p_t>()),  bs::One<r_t>());
  STF_EQUAL(toint(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" toint signed",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint;
  using p_t = bs::pack<T>;
  using r_t = decltype(toint(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t, signed>));

  // specific values tests
  STF_EQUAL(toint(bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(toint(bs::One<p_t>()),  bs::One<r_t>());
  STF_EQUAL(toint(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for signed_int_


