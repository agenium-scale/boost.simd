//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/tenpower.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/ratio.hpp>


template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  using fT =  bd::as_floating_t<T>;
  using f_t = bs::pack<fT, N>;

  T a1[N];
  fT b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::tenpower(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  f_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::tenpower(aa1), bb, 0.5);
}

STF_CASE_TPL("Check tenpower on pack" , (int32_t)(int64_t)(uint32_t)(uint64_t))//STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}




STF_CASE_TPL (" tenpower unsigned_int", STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tenpower;
  using p_t = bs::pack<T>;
  using r_t = decltype(tenpower(p_t()));

  STF_TYPE_IS(r_t, bd::as_floating_t<p_t>);

  // specific values tests
  STF_ULP_EQUAL(tenpower(bs::One<p_t>()), r_t(10), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Two<p_t>()), r_t(100), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Zero<p_t>()), bs::One<r_t>(), 0.5);
} // end of test for unsigned_int_

STF_CASE_TPL (" tenpower signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tenpower;
  using p_t = bs::pack<T>;
  using r_t = decltype(tenpower(p_t()));

  STF_TYPE_IS(r_t, bd::as_floating_t<p_t>);


  // specific values tests
  STF_ULP_EQUAL(tenpower(bs::Mone<p_t>()), r_t(1.0/10), 0.5);
  STF_ULP_EQUAL(tenpower(bs::One<p_t>()), bs::Ten<r_t>(), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Two<p_t>()), r_t(100), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Mtwo<p_t>()), r_t(1.0/100), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Zero<p_t>()), bs::One<r_t>(), 0.5);
} // end of test for signed_int_
