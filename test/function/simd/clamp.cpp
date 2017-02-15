//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/clamp.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N],  b[N];
  for(int i = 0; i < N; ++i)
  {
     a1[i] = i;
     b[i]  = bs::clamp(a1[i], T(0.2*N), T(0.7*N));
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(0.2*N);
  p_t aa3(0.7*N);
  p_t bb (&b [0], &b [0]+N);

  STF_IEEE_EQUAL(bs::clamp(aa1, aa2, aa3), bb);
}

STF_CASE_TPL("Check clamp on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

STF_CASE_TPL("Check pedantic clamp on pack nan" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  auto nan =  bs::Nan<p_t>();
  STF_IEEE_EQUAL(bs::pedantic_(bs::clamp)(nan,p_t(2),p_t(4)) , nan);
}
