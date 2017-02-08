//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/is_not_denormal.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using lT =  bs::logical<T>;
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<lT, N>;

  T a1[N];
  lT b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : bs::Smallestposval<T>()/T(2);
    b[i] = bs::is_not_denormal(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  pl_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::is_not_denormal(aa1), bb);
}

STF_CASE_TPL("Check is_not_denormal on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
