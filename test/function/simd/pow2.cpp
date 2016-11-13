//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/pow2.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/four.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N],  b[N];
  bd::as_integer_t<T> a2 =  2;
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     b[i] = bs::pow2(a1[i], a2);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);//logical
  STF_IEEE_EQUAL(bs::pow2(aa1, a2), bb);
}

STF_CASE_TPL("Check pow2 on pack" , (float))//STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}




STF_CASE_TPL (" pow2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow2;
  using p_t = bs::pack<T>;
  using ip_t = bd::as_integer_t<p_t>;
  using r_t = decltype(pow2(p_t(), ip_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(pow2(bs::Inf<p_t>(),  2), bs::Inf<r_t>());
  STF_EQUAL(pow2(bs::Minf<p_t>(), 2), bs::Minf<r_t>());
  STF_IEEE_EQUAL(pow2(bs::Nan<p_t>(),  2), bs::Nan<r_t>());
  STF_EQUAL(pow2(bs::Inf<p_t>(),  p_t(2.5)), bs::Inf<r_t>());
  STF_EQUAL(pow2(bs::Minf<p_t>(), p_t(2.5)), bs::Minf<r_t>());
  STF_IEEE_EQUAL(pow2(bs::Nan<p_t>(),  p_t(2.5)), bs::Nan<r_t>());
  STF_EQUAL(pow2(bs::Mone<p_t>(), 2), -bs::Four<r_t>());
  STF_EQUAL(pow2(bs::One<p_t>(),  2), bs::Four<r_t>());
  STF_EQUAL(pow2(bs::Zero<p_t>(), 2), bs::Zero<r_t>());
  STF_EQUAL(pow2(bs::Mone<p_t>(), p_t(2.5)), -bs::Four<r_t>());
  STF_EQUAL(pow2(bs::One<p_t>(),  p_t(2.5)), bs::Four<r_t>());
  STF_EQUAL(pow2(bs::Zero<p_t>(), p_t(2.5)), bs::Zero<r_t>());
}
