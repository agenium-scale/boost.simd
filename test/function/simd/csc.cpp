//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/csc.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);
    b[i] = bs::csc(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::csc(aa1), bb, 0.5);
}

STF_CASE_TPL("Check csc on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void testcs(Env& $)
{
  namespace bst = bs::tag;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);

    b[i] = bs::csc(a1[i], bst::clipped_small_) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::csc(aa1, bst::clipped_small_), bb, 0.5);

}

STF_CASE_TPL("Check csc csc clipped_small_ on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  testcs<T, N>($);
  testcs<T, N/2>($);
  testcs<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void testcm(Env& $)
{
  namespace bst = bs::tag;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);

    b[i] = bs::csc(a1[i], bst::clipped_medium_) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::csc(aa1, bst::clipped_medium_), bb, 0.5);
}

STF_CASE_TPL("Check csc csc clipped_medium_ on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  testcm<T, N>($);
  testcm<T, N/2>($);
  testcm<T, N*2>($);
}



STF_CASE_TPL (" csc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::csc;
  using p_t = bs::pack<T>;


  using r_t = decltype(csc(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(csc(-bs::Zero<p_t>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Inf<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Minf<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Nan<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Zero<p_t>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(csc(-bs::Pio_2<p_t>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(-bs::Pio_4<p_t>()), -bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Pio_2<p_t>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(csc(bs::Pio_4<p_t>()), bs::Sqrt_2<r_t>(), 0.5);
}
