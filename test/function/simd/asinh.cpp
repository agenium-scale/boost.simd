//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/asinh.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/eps.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(i);
    b[i] = bs::asinh(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[N]);
  p_t bb (&b[0], &b[N]);
  STF_ULP_EQUAL(bs::asinh(aa1), bb, 0.5);
}

STF_CASE_TPL("Check asinh on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" asinh",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::asinh;
  using p_t = bs::pack<T>;

  using r_t = decltype(asinh(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t,p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(asinh(bs::Inf<p_t>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(asinh(bs::Minf<p_t>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(asinh(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(asinh(bs::Zero<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(asinh(bs::Valmax<p_t>()), p_t(std::asinh(bs::Valmax<T>())), 0.5);
  STF_ULP_EQUAL(asinh(bs::rec(bs::Sqrteps<p_t>())*2),   p_t(std::asinh(bs::rec(bs::Sqrteps<T>())*2)), 0.5);
  STF_ULP_EQUAL(asinh(bs::Eps<p_t>()), bs::Eps<p_t>(), 0.5);
 for(T i=T(0.1); i <= T(1.1); i+= T(0.5))
 {
   T ri =  bs::rec(i);
   STF_ULP_EQUAL(asinh(p_t(i)), p_t(std::asinh(i)), 0.5);
   STF_ULP_EQUAL(asinh(p_t(ri)),p_t(std::asinh(ri)), 0.5);
 }
}
