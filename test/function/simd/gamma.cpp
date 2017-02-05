//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/gamma.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/five.hpp>
#include <boost/simd/function/rsqrt.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void limit_test(Env& $)
{
  using p_t = bs::pack<T, N>;

  STF_ULP_EQUAL (bs::gamma(p_t(1))            , p_t(1), 0.5);
  STF_IEEE_EQUAL(bs::gamma(p_t(0))            , p_t(bs::Inf<T>())        );
  STF_IEEE_EQUAL(bs::gamma(p_t(bs::Inf<T>())) , bs::Inf<p_t>());
  STF_IEEE_EQUAL(bs::gamma(p_t(bs::Minf<T>())), p_t(bs::Nan<T>())        );
}

STF_CASE_TPL("Check gamma limit cases" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  limit_test<T, N>($);
  limit_test<T, N/2>($);
  limit_test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);
    b[i] = bs::gamma(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::gamma(aa1), bb, 0.5);
}

STF_CASE_TPL("Check gamma on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
   test<T, N>($);
   test<T, N/2>($);
   test<T, N*2>($);
}



STF_CASE_TPL (" gamma",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::gamma;
  using p_t = bs::pack<T>;

  using r_t = decltype(gamma(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(gamma(bs::Minf<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Inf<p_t>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(gamma(bs::Zero<p_t>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(gamma(bs::Mzero<p_t>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(gamma(p_t(1)), p_t(1), 0);
  STF_ULP_EQUAL(gamma(p_t(2)), p_t(1), 0);
  STF_ULP_EQUAL(gamma(p_t(3)), p_t(2), 0);
  STF_ULP_EQUAL(gamma(p_t(5)), p_t(24), 0);
 }
