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
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/zero.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N], a2[N], c[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = ((i%2) ? T(2*i) : T(-2*i))/T(3);
    a2[i] = T(2*i+1)/T(2);
    b[i] = bs::nearbyint(a1[i]) ;
    c[i] = bs::nearbyint(a2[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb (&b[0], &b[0]+N);
  p_t cc (&c[0], &c[0]+N);
  STF_IEEE_EQUAL(bs::nearbyint(aa1), bb);
  STF_IEEE_EQUAL(bs::nearbyint(aa2), cc);
}

STF_CASE_TPL("Check nearbyint on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL("Check nearbyint on halfs" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  p_t a(1.5);
  p_t b(2.5);
  for(int i = 1; i <= 9; i+= 1)
  {
    STF_IEEE_EQUAL(bs::nearbyint(p_t(i+T(0.5))), p_t(i%2 ? i+1 : i ));
    STF_IEEE_EQUAL(bs::nearbyint(p_t(-i+T(0.5))), p_t(i%2 ? -i+1 : -i ));
  }
  STF_EXPECT(bs::is_negative(nearbyint(bs::Mzero<T>())));
  STF_EXPECT(bs::is_positive(nearbyint(bs::Zero<T>())));
}
