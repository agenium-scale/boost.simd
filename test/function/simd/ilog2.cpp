//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/ilog2.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using iT  = bd::as_integer_t<T>;
  using i_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N];

  a1[0] = T(3);
  b[0]  = bs::ilog2(a1[0]);

  for(std::size_t i = 1; i < N; ++i)
  {
    a1[i] = bs::max(T(a1[i-1]*T(3)), T(1));
    b[i]  = bs::ilog2(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  i_t bb(&b[0], &b[0]+N);

  STF_EQUAL(bs::ilog2(aa1), bb);
}

STF_CASE_TPL("Check ilog2 on pack",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
   test<T, N>(runtime);
   test<T, N/2>(runtime);
   test<T, N*2>(runtime);
}
