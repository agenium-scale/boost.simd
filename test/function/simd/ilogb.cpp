//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/ilogb.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/four.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using iT  = bd::as_integer_t<T>;
  using i_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(N+i+1);
     b[i] = bs::ilogb(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  i_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::ilogb(aa1), bb);
}

STF_CASE_TPL("Check ilogb on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}


STF_CASE_TPL (" ilogb real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilogb;
  using p_t = bs::pack<T>;
  using r_t = decltype(ilogb(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ilogb(bs::Minf<p_t>()), bs::Valmax<r_t>());
  STF_EQUAL(ilogb(bs::Inf<p_t>()), bs::Valmax<r_t>());
  STF_EQUAL(ilogb(bs::Nan<p_t>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(ilogb(bs::Mone<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::One<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Two<p_t>()), bs::One<r_t>());
  STF_EQUAL(ilogb(bs::Four<p_t>()), bs::Two<r_t>());
  STF_EQUAL(ilogb(bs::Zero<p_t>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" ilogb unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilogb;
  using p_t = bs::pack<T>;
  using r_t = decltype(ilogb(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t>));

  // specific values tests
  STF_EQUAL(ilogb(bs::One<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Two<p_t>()), bs::One<r_t>());
  STF_EQUAL(ilogb(bs::Zero<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Four<p_t>()), bs::Two<r_t>());
}

STF_CASE_TPL (" ilogb signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilogb;
  using p_t = bs::pack<T>;
  using r_t = decltype(ilogb(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t>));

  // specific values tests
  STF_EQUAL(ilogb(bs::Mone<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::One<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Two<p_t>()), bs::One<r_t>());
  STF_EQUAL(ilogb(bs::Zero<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(ilogb(bs::Four<p_t>()), bs::Two<r_t>());
}

STF_CASE_TPL (" ilogb pedantic real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ilogb;
  using p_t = bs::pack<T>;
  using r_t = decltype(bs::pedantic_(ilogb)(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::pedantic_(ilogb)(bs::Minf<p_t>()), bs::Valmax<r_t>());
  STF_EQUAL(bs::pedantic_(ilogb)(bs::Inf<p_t>()),  bs::Valmax<r_t>());
  STF_EQUAL(bs::pedantic_(ilogb)(bs::Nan<p_t>()),  r_t(FP_ILOGBNAN));
#endif
  STF_EQUAL(bs::pedantic_(ilogb)(bs::Mone<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(bs::pedantic_(ilogb)(bs::One<p_t>()),  bs::Zero<r_t>());
  STF_EQUAL(bs::pedantic_(ilogb)(bs::Two<p_t>()),  bs::One<r_t>());
  STF_EQUAL(bs::pedantic_(ilogb)(bs::Four<p_t>()), bs::Two<r_t>());
  STF_EQUAL(bs::pedantic_(ilogb)(bs::Zero<p_t>()), r_t(FP_ILOGB0));
}
