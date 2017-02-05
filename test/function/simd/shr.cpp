//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shr.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/three.hpp>

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
    b[i] = bs::shr(a1[i], sh1);
    c[i] = bs::shr(a1[i], sh2);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t cc(&c[0], &c[0]+N);

  STF_EQUAL(bs::shr(aa1, sh1), bb);
  STF_EQUAL(bs::shr(aa1, sh2), cc);
}

STF_CASE_TPL("Check shr on pack with integral shift" , STF_INTEGRAL_TYPES)
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
    b[i] = bs::shr(a1[i],sh[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  i_t sh1(&sh[0], &sh[0]+N);
  STF_EQUAL(bs::shr(aa1, sh1), bb);
}

STF_CASE_TPL("Check shr on pack with pack shift" , STF_INTEGRAL_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}



STF_CASE_TPL (" shr uit",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::shr;
  using p_t = bs::pack<T>;
  using ip_t = bd::as_integer_t<T, unsigned>;
  using r_t = decltype(shr(p_t(), ip_t()));

  // return type conformity test
  STF_TYPE_IS( r_t, p_t );

  // specific values tests
  STF_EQUAL(shr(p_t(2),1), bs::One<p_t>());
  STF_EQUAL(shr(bs::Valmax<p_t>(),(sizeof(T)*8-1)), bs::One<r_t>());
  STF_EQUAL(shr(bs::Valmax<p_t>(),(sizeof(T)*8-2)), bs::Three<r_t>());
  STF_EQUAL(shr(bs::One<p_t>(),1), bs::Zero<r_t>());
  STF_EQUAL(shr(bs::Zero<p_t>(),1), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" shr si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::shr;
  using p_t = bs::pack<T>;
  using ip_t = bd::as_integer_t<T, unsigned>;
  using r_t = decltype(shr(p_t(), ip_t()));

  // return type conformity test
  STF_TYPE_IS( r_t, p_t );

  // specific values tests
  STF_EQUAL(shr(p_t(2),1), bs::One<p_t>());
  STF_EQUAL(shr(bs::Mone<p_t>(),(sizeof(T)*8-1)), bs::One<r_t>());
  STF_EQUAL(shr(bs::Mone<p_t>(),(sizeof(T)*8-2)), bs::Three<r_t>());
  STF_EQUAL(shr(bs::One<p_t>(),1), bs::Zero<r_t>());
  STF_EQUAL(shr(bs::Zero<p_t>(),1), bs::Zero<r_t>());
} // end of test for unsigned_int_
