//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/sincospi.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], c[N], s[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(2*i)/N : -T(2*i)/N;
    std::tie(s[i], c[i])= bs::sincospi(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t ss (&s[0], &s[0]+N);
  p_t cc (&c[0], &c[0]+N);
  p_t ss1, cc1;
  std::tie(ss1, cc1)= bs::sincospi(aa1) ;
  STF_ULP_EQUAL(ss1, ss, 0.5);
  STF_ULP_EQUAL(cc1, cc, 0.5);
}

STF_CASE_TPL("Check sincospi on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void testr(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], c[N], s[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = ((i%2) ? T(i) : -T(i))*T(0.25)/N;
    std::tie(s[i], c[i])= bs::restricted_(bs::sincospi)(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t ss (&s[0], &s[0]+N);
  p_t cc (&c[0], &c[0]+N);
  p_t ss1, cc1;
  std::tie(ss1, cc1)= bs::restricted_(bs::sincospi)(aa1);

  STF_ULP_EQUAL(ss1, ss,0.5);
  STF_ULP_EQUAL(cc1, cc,0.5);
}

STF_CASE_TPL("Check restricted sincospi on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  testr<T, N>($);
  testr<T, N/2>($);
  testr<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void testc(Env& $)
{
  namespace bst = bs::tag;
  using p_t = bs::pack<T, N>;

  T a1[N], c[N], s[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = ((i%2) ? T(i) : -T(i))*T(0.25)/N;
    std::tie(s[i], c[i])= bs::sincospi(a1[i], bst::clipped_medium_);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t ss (&s[0], &s[0]+N);
  p_t cc (&c[0], &c[0]+N);
  p_t ss1, cc1;
  std::tie(ss1, cc1)= bs::sincospi(aa1, bst::clipped_medium_);

  STF_ULP_EQUAL(ss1, ss,0.5);
  STF_ULP_EQUAL(cc1, cc,0.5);
}

STF_CASE_TPL("Check clipped sincospi on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  testc<T, N>($);
  testc<T, N/2>($);
  testc<T, N*2>($);
}
