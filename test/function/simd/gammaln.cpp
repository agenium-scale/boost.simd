//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/gammaln.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
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
#include <boost/simd/constant/mtwo.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void limit_test(Env& $)
{
  using p_t = bs::pack<T, N>;
  using bs::gammaln;

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(gammaln(bs::Inf<p_t>()), bs::Inf<p_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Minf<p_t>()), bs::Nan<p_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Nan<p_t>()), bs::Nan<p_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Zero<p_t>()), bs::Inf<p_t>(), 0);
#endif
  STF_ULP_EQUAL(gammaln(bs::Mone<p_t>()), bs::Inf<p_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Mtwo<p_t>()), bs::Inf<p_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::One<p_t>()), bs::Zero<p_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Two<p_t>()), bs::Zero<p_t>(), 0);
  STF_ULP_EQUAL(gammaln(bs::Mzero<p_t>()),         bs::Inf<p_t>(), 0);

  STF_ULP_EQUAL(gammaln(bs::Halfeps<p_t>()),       p_t( bs::std_(gammaln)(bs::Halfeps<p_t>())), 1);
  STF_ULP_EQUAL(gammaln(bs::Eps<p_t>()),           p_t(bs::std_(gammaln)(bs::Eps<p_t>())), 0.5);
  STF_ULP_EQUAL(gammaln(bs::Half<p_t>()),          p_t(bs::std_(gammaln)(bs::Half<p_t>())), 0.5);
  STF_ULP_EQUAL(gammaln(p_t(1.5)),                 p_t(bs::std_(gammaln)(T(1.5))), 1.5);
  STF_ULP_EQUAL(gammaln(p_t(2.5)),                 p_t(bs::std_(gammaln)(T(2.5))), 0.5);
  STF_ULP_EQUAL(gammaln(p_t(13)) ,                 p_t(bs::std_(gammaln)(T(13))), 0.5);
  STF_ULP_EQUAL(gammaln(p_t(13.5)) ,               p_t(bs::std_(gammaln)(T(13.5))), 0.5);
  STF_ULP_EQUAL(gammaln(p_t(-0.1)),                p_t(bs::std_(gammaln)(T(-0.1))),         1);
  STF_ULP_EQUAL(gammaln(-bs::Half<p_t>()),         p_t(bs::std_(gammaln)(-bs::Half<T>())),  0.5);
  STF_ULP_EQUAL(gammaln(-bs::Halfeps<p_t>()),      p_t(bs::std_(gammaln)(-bs::Halfeps<T>())), 0.5);
  STF_ULP_EQUAL(gammaln(p_t(-27.5)),               p_t(bs::std_(gammaln)(T(-27.5))),            3);
}

STF_CASE_TPL("Check gammaln limit cases" , STF_IEEE_TYPES)
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
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::gammaln(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::gammaln(aa1), bb, 0.5);
}

STF_CASE_TPL("Check gammaln on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
   test<T, N>($);
   test<T, N/2>($);
   test<T, N*2>($);
}
