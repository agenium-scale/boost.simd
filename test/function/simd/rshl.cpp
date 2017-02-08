//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/rshl.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, int N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N];
  T b[N], c[N];
  int sh1 =  sizeof(T)*8-1;

  int sh2 =  -sh1;

  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i ) : T(-i);
    b[i] = bs::rshl(a1[i], sh1);
    c[i] = bs::rshl(a1[i], sh2);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t cc(&c[0], &c[0]+N);

  STF_EQUAL(bs::rshl(aa1, sh1), bb);
  STF_EQUAL(bs::rshl(aa1, sh2), cc);
}

STF_CASE_TPL("Check rshl on pack with integral shift" , STF_SIGNED_INTEGRAL_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

template <typename T, int N, typename Env>
void tests(Env& runtime)
{
  using iT =  bd::as_integer_t<T>;
  using p_t = bs::pack<T, N>;
  using i_t = bs::pack<iT, N>;

  T a1[N], b[N];
  iT sh[N];

  for(int i = 0; i < N; ++i)
  {
    sh[i] = (i%2) ?i%(8*sizeof(T)) : -(i%(8*sizeof(T)));
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::rshl(a1[i],sh[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  i_t sh1(&sh[0], &sh[0]+N);
  STF_EQUAL(bs::rshl(aa1, sh1), bb);
}

STF_CASE_TPL("Check rshl on pack with pack shift" , STF_SIGNED_INTEGRAL_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  tests<T, N>(runtime);
  tests<T, N/2>(runtime);
  tests<T, N*2>(runtime);
}
