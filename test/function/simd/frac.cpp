//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/frac.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::frac(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::frac(aa1), bb);
}

STF_CASE_TPL("Check frac on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" frac real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::frac;
  using p_t = bs::pack<T>;
  using r_t = decltype(frac(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(frac(bs::Inf<p_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(frac(bs::Minf<p_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(frac(bs::Nan<p_t>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(frac(bs::Mone<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::One<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::Zero<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(frac(p_t(1.5)),  bs::Half<r_t>());
  STF_EQUAL(frac(p_t(-1.5)),  bs::Mhalf<r_t>());
}

STF_CASE_TPL (" frac unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::frac;
  using p_t = bs::pack<T>;
  using r_t = decltype(frac(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(frac(bs::One<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::Zero<p_t>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" frac signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::frac;
  using p_t = bs::pack<T>;
  using r_t = decltype(frac(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(frac(bs::Mone<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::One<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(frac(bs::Zero<p_t>()), bs::Zero<r_t>());
}


