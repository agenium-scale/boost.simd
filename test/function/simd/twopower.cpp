//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/twopower.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i)%(8*sizeof(T));
    b[i] = bs::twopower(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::twopower(aa1), bb);
}

STF_CASE_TPL("Check twopower on pack" , STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL (" twopower ui",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::twopower;
  using p_t = bs::pack<T>;
  using r_t = decltype(twopower(p_t()));

  STF_TYPE_IS( r_t, p_t );

  // specific values tests
  STF_EQUAL(twopower(bs::Zero<p_t>()), bs::One<r_t>());

  for(unsigned int i=0; i < sizeof(T)*8 ; i++)
 {
   STF_EQUAL(twopower(p_t(i)), p_t(T(1) << i));
 }
} // end of test for unsigned_int_

STF_CASE_TPL (" twopowersi",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::twopower;
  using p_t = bs::pack<T>;
  using r_t = decltype(twopower(p_t()));

  // return type conformity test
  STF_TYPE_IS( r_t, p_t );

  // specific values tests
  STF_EQUAL(twopower(bs::Zero<p_t>()), bs::One<r_t>());
  STF_EQUAL(twopower(bs::Mone<p_t>()), bs::Zero<r_t>());

  for(unsigned int i=0; i < sizeof(T)*8-1 ; i++)
  {
    STF_EQUAL(twopower(p_t(i)), p_t(T(1) << i));
  }

} // end of test for unsigned_int_

