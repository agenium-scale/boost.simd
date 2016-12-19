//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, int N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;
  using fT = bd::as_floating_t<T>;
  using f_t =bs::pack<fT, N>;

  T a1[N];
  fT b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::tofloat(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  f_t bb (&b[0], &b[0]+N);

  STF_IEEE_EQUAL(bs::tofloat(aa1), bb);
}

STF_CASE_TPL("Check tofloat on pack" , (std::uint32_t)(std::uint64_t)(std::int32_t)(std::int64_t))
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}



STF_CASE_TPL (" tofloat real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tofloat;
  using p_t = bs::pack<T>;

  using r_t = decltype(tofloat(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(tofloat(bs::Inf<p_t>()), bs::Inf<r_t>());
  STF_EQUAL(tofloat(bs::Minf<p_t>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(tofloat(bs::Nan<p_t>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(tofloat(bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(tofloat(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(tofloat(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" tofloat unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tofloat;
  using p_t = bs::pack<T>;

  using r_t = decltype(tofloat(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_floating_t<p_t>);

  // specific values tests
  STF_EQUAL(tofloat(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(tofloat(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" tofloat signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tofloat;
  using p_t = bs::pack<T>;

  using r_t = decltype(tofloat(p_t()));


  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_floating_t<p_t>);

  // specific values tests
  STF_EQUAL(tofloat(bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(tofloat(bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(tofloat(bs::Zero<p_t>()), bs::Zero<r_t>());
} // end of test for signed_int_

