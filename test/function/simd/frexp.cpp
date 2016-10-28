//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/fast.hpp>
#include <tuple>
#include <utility>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;
  using iT = bd::as_integer_t<T>;
  using i_t = bs::pack<iT, N>;

  T a1[N], m[N];
  iT e[N];

  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     std::tie(m[i], e[i])   = bs::frexp(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t mm1, mm(&m[0], &m[0]+N);
  i_t ee1, ee(&e[0], &e[0]+N);

  std::tie(mm1, ee1) = bs::frexp(aa1);
  STF_IEEE_EQUAL(mm1, mm);
  STF_IEEE_EQUAL(ee1, ee);
}

STF_CASE_TPL("Check frexp on pack" , STF_IEEE_TYPES)
{

  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test_fast(Env& $)
{
  using p_t = bs::pack<T, N>;
  using iT = bd::as_integer_t<T>;
  using i_t = bs::pack<iT, N>;

  T a1[N], m[N];
  iT e[N];

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(1+i) : T(1-i);
    std::tie(m[i], e[i]) = bs::fast_(bs::frexp)(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t mm , mm1(&m[0], &m[0]+N);
  i_t ee , ee1(&e[0], &e[0]+N);
  std::tie(mm, ee) = bs::fast_(bs::frexp)(aa1);

  STF_IEEE_EQUAL(mm, mm1);
  STF_IEEE_EQUAL(ee, ee1);
}

STF_CASE_TPL("Check fast(frexp) on pack" , STF_IEEE_TYPES)
{

  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test_fast<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
