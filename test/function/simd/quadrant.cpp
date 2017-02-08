//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/quadrant.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/is_even.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;

  T a1[N];
  T b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = T(i);
    b[i] = bs::quadrant(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_EQUAL(bs::quadrant(aa1), bb);
}

STF_CASE_TPL("Check quadrant on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

STF_CASE_TPL (" quadrant real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

   using bs::quadrant;
  using p_t = bs::pack<T>;

   using r_t = decltype(quadrant(T()));
   using iT =  bd::as_integer_t<T>;
   STF_TYPE_IS(r_t, T);

  for(iT i=0; i < 128; i++)
  {
    STF_EQUAL(quadrant(p_t(i)), p_t(i&iT(3)));
  }
} // end of test for floating_

