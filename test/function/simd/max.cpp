//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/max.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::max(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::max(aa1, aa2), bb);
}

STF_CASE_TPL("Check max on integral pack" , STF_INTEGRAL_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test_r(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];

  a1[0]   = bs::Nan<T>();
  a2[N-1] = bs::Nan<T>();
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::max(a1[i], a2[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_IEEE_EQUAL(bs::max(aa1, aa2), bb);
}

STF_CASE_TPL("Check max on floating point pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test_r<T, N>($);
  test_r<T, N/2>($);
  test_r<T, N*2>($);
}


STF_CASE_TPL("Check max on nans  pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  {
    using p_t = bs::pack<T, N>;
    p_t n =  bs::Nan<p_t>();
    p_t o =  bs::One<p_t>();
    STF_IEEE_EQUAL(bs::max(n, o), n);
    STF_IEEE_EQUAL(bs::max(o, n), o);
  }

}
