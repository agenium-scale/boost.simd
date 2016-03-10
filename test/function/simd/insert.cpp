//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/definition/insert.hpp>
#include <boost/simd/function/insert.hpp>
#include <boost/simd/constant/constant.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;


template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  p_t p;
  STF_TYPE_IS(void, decltype(bs::insert(p, std::size_t(), T())));

  T a1[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i*2);
  }
  p_t aa1(&a1[0], &a1[N]);
  for(std::size_t i = 0; i < N; ++i)
  {
    bs::insert(aa1, i, T(i+1));
    a1[i] = T(i+1);
    STF_IEEE_EQUAL(aa1, p_t(&a1[0], &a1[N]));
  }
}

template <typename T, std::size_t N, std::size_t I, typename Env> struct test_static
{
  template < class P>
  void operator()(Env& $, P & aa1,  T a1[N])
  {
    using p_t = bs::pack<T, N>;
    a1[I] = T(I+5);
    p_t aa2(&a1[0], &a1[N]);
    bs::insert<I>(aa1, T(I+5));
    STF_IEEE_EQUAL(aa1,  aa2);
    test_static < T, N, I-1, Env>()($, aa1, a1);
  }
};

template <typename T, std::size_t N, typename Env> struct test_static < T, N, 0, Env>
{
  template < class P>
  void operator()(Env& $, P & aa1,  T a1[N])
  {
    using p_t = bs::pack<T, N>;
    bs::insert<0>(aa1, T(5));
    a1[0] = T(5);
    p_t aa2(&a1[0], &a1[N]);
    STF_IEEE_EQUAL(aa1,  aa2);
  }
};


template <typename T, std::size_t N, typename Env>
void test_st(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  p_t p;
  STF_TYPE_IS(void, decltype(bs::insert<0>(p, T())));


  T a1[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i*2);
  }
  p_t aa1(&a1[0], &a1[N]);
  test_static<T, N, N-1, Env>()($, aa1, a1);
}

STF_CASE_TPL("Check insert on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = p_t::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
  test_st<T, N>($);
  test_st<T, N/2>($);
  test_st<T, N*2>($);
}
