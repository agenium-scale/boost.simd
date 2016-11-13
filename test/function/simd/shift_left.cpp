//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, int N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N];
  T b[N], c[N];
  std::size_t sh1 =  sizeof(T)*8-1;

  int sh2 =  1;

  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::shift_left(a1[i], sh1);
    c[i] = bs::shift_left(a1[i], sh2);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t cc(&c[0], &c[0]+N);

  STF_EQUAL(bs::shift_left(aa1, sh1), bb);
  STF_EQUAL(bs::shift_left(aa1, sh2), cc);
  STF_EQUAL((aa1 << sh1), bb);
  STF_EQUAL((aa1 << sh2), cc);
}

STF_CASE_TPL("Check shift_left on pack with integral shift" , STF_INTEGRAL_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, int N, typename Env>
void tests(Env& $)
{
  using iT =  bd::as_integer_t<T>;
  using p_t = bs::pack<T, N>;
  using i_t = bs::pack<iT, N>;

  T a1[N], b[N];
  iT sh[N];

  for(int i = 0; i < N; ++i)
  {
    sh[i] = i%(8*sizeof(T));
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::shift_left(a1[i],sh[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  i_t sh1(&sh[0], &sh[0]+N);
  STF_EQUAL(bs::shift_left(aa1, sh1), bb);
  STF_EQUAL((aa1 << sh1), bb);
}

STF_CASE_TPL("Check shift_left on pack with pack shift" , STF_INTEGRAL_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}

STF_CASE_TPL (" shift_left_integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::shift_left;
  using p_t = bs::pack<T>;
  using ip_t =  boost::dispatch::as_integer_t<p_t>;
  using r_t = decltype(shift_left(p_t(),ip_t()));
  typedef p_t wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(shift_left(bs::One<p_t>(),bs::One<ip_t>()), bs::Two<r_t>());
  STF_EQUAL(shift_left(bs::One<p_t>(),bs::Zero<ip_t>()), bs::One<r_t>());
  STF_EQUAL(shift_left(bs::Zero<p_t>(),bs::One<ip_t>()), bs::Zero<r_t>());
} // end of test for integer_

STF_CASE_TPL (" shift_left_real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::shift_left;
  using p_t = bs::pack<T>;
  using ip_t =  boost::dispatch::as_integer_t<p_t>;
  using r_t = decltype(shift_left(p_t(),ip_t()));
  typedef p_t wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(shift_left(bs::One<p_t>(),bs::Zero<ip_t>()), bs::One<r_t>());
  STF_EQUAL(shift_left(bs::Zero<p_t>(),bs::One<ip_t>()), bs::Zero<r_t>());
} // end of test for floating_
