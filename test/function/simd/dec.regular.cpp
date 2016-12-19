//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================

#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/two.hpp>


template <typename T, std::size_t N, typename Env>
void pre_test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i+1) : T(2+i);
    b[i] = a1[i] - T(1);
  }

  p_t aa1(&a1[0], &a1[0]+N), aa2;
  p_t bb(&b[0], &b[0]+N);

  aa2 = --aa1;
  STF_EQUAL(aa2, bb);
  STF_EQUAL(aa1, bb);
}

STF_CASE_TPL("Check pre-decrement on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  pre_test<T, N>($);
  pre_test<T, N/2>($);
  pre_test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void post_test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(1+i) : T(2+i);
    b[i] = a1[i] - T(1);
  }

  p_t aa1(&a1[0], &a1[0]+N), prev(aa1), aa2;
  p_t bb(&b[0], &b[0]+N);

  aa2 = aa1--;
  STF_EQUAL(aa2, prev);
  STF_EQUAL(aa1, bb);
}


STF_CASE_TPL (" dec signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::dec;
  using p_t = bs::pack<T>;

  // return type conformity test
  STF_EXPR_IS(dec(p_t()), p_t);

  // specific values tests
  STF_EQUAL(dec(bs::Mone<p_t>()), bs::Mtwo<p_t>());
  STF_EQUAL(dec(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(dec(bs::Zero<p_t>()), bs::Mone<p_t>());
}

STF_CASE_TPL (" decunsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::dec;
  using p_t = bs::pack<T>;

  // return type conformity test
  STF_EXPR_IS(dec(p_t()), p_t);

  // specific values tests
  STF_EQUAL(dec(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(dec(bs::Two<p_t>()), bs::One<p_t>());
  STF_EQUAL(dec(bs::Zero<p_t>()), bs::Valmax<p_t>());
}

STF_CASE_TPL(" dec floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::dec;
  using p_t = bs::pack<T>;

  // return type conformity test
  STF_EXPR_IS(dec(p_t()), p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(dec(bs::Inf<p_t>()), bs::Inf<p_t>());
  STF_IEEE_EQUAL(dec(bs::Nan<p_t>()), bs::Nan<p_t>());
  STF_EQUAL(dec(bs::Minf<p_t>()), bs::Minf<p_t>());
#endif
  STF_EQUAL(dec(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(dec(bs::Two<p_t>()), bs::One<p_t>());
  STF_EQUAL(dec(bs::Zero<p_t>()), bs::Mone<p_t>());
}
