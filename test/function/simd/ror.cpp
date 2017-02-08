//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/ror.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;
  int M =  sizeof(T)*8-1;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], b[N], c[N], d[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     b[i] = bs::ror(a1[i], 1);
     c[i] = bs::ror(a1[i], M/2);
     d[i] = bs::ror(a1[i], M-1);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t cc(&c[0], &c[0]+N);
  p_t dd(&d[0], &d[0]+N);
  STF_IEEE_EQUAL(bs::ror(aa1, 1), bb);
  STF_IEEE_EQUAL(bs::ror(aa1, M/2), cc);
  STF_IEEE_EQUAL(bs::ror(aa1, M-1), dd);
}

STF_CASE_TPL("Check ror on pack and scalar" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
template <typename T, std::size_t N, typename Env>
void tests(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  int M =  sizeof(T)*8-1;
  using iT =  bd::as_integer_t<p_t, unsigned>;
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], b[N], c[N], d[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     b[i] = bs::ror(a1[i],1);
     c[i] = bs::ror(a1[i], M/2);
     d[i] = bs::ror(a1[i], M-1);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t cc(&c[0], &c[0]+N);
  p_t dd(&d[0], &d[0]+N);
  STF_IEEE_EQUAL(bs::ror(aa1, iT(1)), bb);
  STF_IEEE_EQUAL(bs::ror(aa1, iT(M/2)), cc);
  STF_IEEE_EQUAL(bs::ror(aa1, iT(M-1)), dd);
}

STF_CASE_TPL("Check ror on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  tests<T, N>(runtime);
  tests<T, N/2>(runtime);
  tests<T, N*2>(runtime);
}
