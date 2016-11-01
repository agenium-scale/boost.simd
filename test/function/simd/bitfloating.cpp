//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/bitfloating.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/bitincrement.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using fT = bd::as_floating_t<T>;
  using f_t =bs::pack<fT, N>;


  T a1[N];
  fT b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::bitfloating(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  f_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::bitfloating(aa1), bb);
}

STF_CASE_TPL("Check bitfloating on pack" , (uint32_t)(uint64_t)(int32_t)(int64_t))//STF_CONVERTIBLE_TYPES) // to define ?
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" bitfloating int_convert",  (int32_t)(int64_t))
{
  namespace bs = boost::simd;
  using bs::bitfloating;
  using p_t = bs::pack<T>;
  using r_t = decltype(bitfloating(p_t()));
  typedef  boost::dispatch::as_floating_t<p_t>  wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(bitfloating(bs::One<p_t>()), bs::Bitincrement<r_t>());
  STF_EQUAL(bitfloating(bs::Mone<p_t>()), -bs::Bitincrement<r_t>());
  STF_EQUAL(bitfloating(bs::Zero<p_t>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" bitfloating uint_convert",  (uint32_t)(uint64_t))
{
  namespace bs = boost::simd;
  using bs::bitfloating;
  using p_t = bs::pack<T>;
  using r_t = decltype(bitfloating(p_t()));
  typedef boost::dispatch::as_floating_t<p_t>  wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(bitfloating(bs::One<p_t>()), bs::Bitincrement<r_t>());
  STF_EQUAL(bitfloating(bs::Zero<p_t>()), bs::Zero<r_t>());
}
