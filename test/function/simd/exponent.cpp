//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T>;
  using ip_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N];

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(37.98*i);
    b[i] = bs::exponent(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  ip_t bb (&b[0], &b[0]+N);

  STF_IEEE_EQUAL(bs::exponent(aa1), bb);
}

STF_CASE_TPL("Check exponent on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void test_invalid(Env& runtime)
{
  using p_t  = bs::pack<T, N>;
  using ip_t = bs::pack<bd::as_integer_t<T>, N>;

  STF_IEEE_EQUAL(bs::exponent(bs::Nan<p_t>()), ip_t(0));
  STF_IEEE_EQUAL(bs::exponent(bs::Inf<p_t>()), ip_t(0));
  STF_IEEE_EQUAL(bs::exponent(bs::Minf<p_t>()), ip_t(0));
}

STF_CASE_TPL("Check exponent on invalid values" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test_invalid<T, N>(runtime);
  test_invalid<T, N/2>(runtime);
  test_invalid<T, N*2>(runtime);
}
