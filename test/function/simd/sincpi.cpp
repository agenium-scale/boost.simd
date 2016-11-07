//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/sincpi.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/sinpi.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);
    b[i] = bs::sincpi(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  p_t cc (&c[0], &c[0]+N);
  STF_EQUAL(bs::sincpi(aa1), bb);
}

STF_CASE_TPL("Check sincpi on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL(" sinc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sincpi;
  using p_t = bs::pack<T>;

  STF_EXPR_IS(sincpi(p_t()),p_t);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sincpi(bs::Inf<p_t>()), bs::Zero<p_t>(), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Minf<p_t>()), bs::Zero<p_t>(), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Nan<p_t>()), bs::Nan<p_t>(), 1.0);
#endif
  STF_ULP_EQUAL(sincpi(-p_t(1)/p_t(2)), p_t(2)/(bs::Pi<p_t>()), 1.0);
  STF_ULP_EQUAL(sincpi(-p_t(1)/p_t(4)), bs::sinpi(p_t(1)/p_t(4))*p_t(4)/(bs::Pi<p_t>()), 1.0);
  STF_ULP_EQUAL(sincpi(p_t(1)/p_t(2)),  p_t(2)/(bs::Pi<p_t>()), 1.0);
  STF_ULP_EQUAL(sincpi(p_t(1)/p_t(4)), bs::sinpi(p_t(1)/p_t(4))*p_t(4)/(bs::Pi<p_t>()), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Eps<p_t>()), bs::One<p_t>(), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Mindenormal<p_t>()), bs::One<p_t>(), 1.0);
  STF_ULP_EQUAL(sincpi(bs::Zero<p_t>()), bs::One<p_t>(), 1.0);
}
