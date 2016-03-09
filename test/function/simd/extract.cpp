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
#include <boost/simd/function/definition/extract.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/constant/constant.hpp>
#include <simd_test.hpp>
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

//   template < size_t N, class T> bd::scalar_of_t<T> extract(const T & )
//   {
//     return (0); //bs::extract(a, brigand::size_t<N>());
//   }

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  STF_TYPE_IS(const T&, decltype(bs::extract(p_t(), std::size_t())));
  p_t p;
  STF_TYPE_IS(T&, decltype(bs::extract(p, std::size_t())));

  T a1[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i*2);
  }
  p_t aa1(&a1[0], &a1[N]);
  for(std::size_t i = 0; i < N; ++i)
  {
    STF_EQUAL(bs::extract(aa1, i), a1[i]);
  }

  for(std::size_t i = 0; i < N; ++i)
  {
    T tmp = a1[i];
    p_t z = aa1;
    bs::extract(z, i) = T(27);
    a1[i] = T(27);
    p_t aa2(&a1[0], &a1[N]);
    STF_IEEE_EQUAL(z, aa2);
    a1[i] = tmp;
  }
}

template <typename T, std::size_t N, std::size_t I, typename Env> struct test_static
{
  template < class P>
  void operator()(Env& $, P const & aa1,  T a1[N])
  {
    STF_EQUAL(bs::extract<I>(aa1), a1[I]);
    test_static < T, N, I-1, Env>()($, aa1, a1);
  }
};

template <typename T, std::size_t N, typename Env> struct test_static < T, N, 0, Env>
{
  template < class P>
  void operator()(Env& $, P const & aa1,  T a1[N])
  {
    STF_EQUAL(bs::extract<0>(aa1), a1[0]);
  }
};


template <typename T, std::size_t N, typename Env>
void test_st(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  STF_TYPE_IS(T, decltype(bs::extract<0>(p_t())));
  p_t p;


  T a1[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i*2);
  }
  p_t aa1(&a1[0], &a1[N]);
  test_static<T, N, N-1, Env>()($, aa1, a1);
}

STF_CASE_TPL("Check extract on pack" , STF_NUMERIC_TYPES)
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
