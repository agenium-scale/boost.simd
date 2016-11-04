//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/ffs.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/signmask.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T>;
  using pi_t = bs::pack<iT, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  T a1[N];
  iT b[N];

  a1[0] = T(1);
  b[0] = bs::ffs(a1[0]);

  for(int i = 1; i < N; ++i)
  {
    a1[i] = T(bs::max(T(a1[i-1]*3), T(1)));
     b[i] = bs::ffs(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  pi_t bb(&b[0], &b[0]+N);

  STF_EQUAL(bs::ffs(aa1), bb);
}

STF_CASE_TPL("Check ffs on pack" ,  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}



STF_CASE_TPL (" ffs real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::ffs;
  using p_t = bs::pack<T>;
  using r_t = decltype(ffs(p_t()));
  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t>));


  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ffs(bs::Inf<p_t>()), r_t(bs::Nbmantissabits<p_t>()+1));
  STF_EQUAL(ffs(bs::Minf<p_t>()), r_t(bs::Nbmantissabits<p_t>()+1));
  STF_EQUAL(ffs(bs::Nan<p_t>()), r_t(bs::One<r_t>()));
#endif
  STF_EQUAL(ffs(bs::Signmask<p_t>()), r_t(sizeof(T)*8));
  STF_EQUAL(ffs(bs::Zero<p_t>()), r_t(bs::Zero<r_t>()));
} // end of test for real_

STF_CASE_TPL (" ffs signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::ffs;
  using p_t = bs::pack<T>;
  using r_t = decltype(ffs(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t>));

  // specific values tests
  STF_EQUAL(ffs(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(ffs(bs::Signmask<p_t>()), r_t(sizeof(T)*8));
  STF_EQUAL(ffs(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for signed_int_

STF_CASE_TPL (" ffs unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::ffs;
  using p_t = bs::pack<T>;
  using r_t = decltype(ffs(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t>));

  // specific values tests
  STF_EQUAL(ffs(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(ffs(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

