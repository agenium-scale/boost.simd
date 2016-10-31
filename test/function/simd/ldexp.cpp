//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using iT = bd::as_integer_t<T>;
  using p_t = bs::pack<T, N>;
  using pi_t = bs::pack<iT, N>;

  T a1[N],  b[N], d[N];
  iT a2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = i%(sizeof(T)*8-1);
     b[i] = bs::ldexp(a1[i], a2[i]);
     d[i] = bs::fast_(bs::ldexp)(a1[i], a2[i]);
   }

  p_t aa1(&a1[0], &a1[0]+N);
  pi_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t dd(&d[0], &d[0]+N);
}

STF_CASE_TPL("Check ldexp on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void tests(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N],  b[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-1.*i);
    b[i] = bs::ldexp(a1[i], 2);
    c[i] = bs::fast_(bs::ldexp)(a1[i], 2);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t cc(&c[0], &c[0]+N);

  STF_IEEE_EQUAL(bs::ldexp(aa1, 2)            , bb);
  STF_IEEE_EQUAL(bs::fast_(bs::ldexp)(aa1, 2) , cc);
}

STF_CASE_TPL("Check ldexp on pack/scalar" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}
