//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/erfc.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/function/is_less.hpp>

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
     a1[i] = T(i)/N;
     b[i] = bs::erfc(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::erfc(aa1), bb, 32);

}

STF_CASE_TPL("Check erfc2 on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" erfc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::erfc;
  using p_t = bs::pack<T>;

  using r_t = decltype(erfc(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(erfc(bs::Inf<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(erfc(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(erfc(bs::Mzero<p_t>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(erfc(p_t(0.1)), p_t(0.887537083981715107796724928256), 10);
  STF_ULP_EQUAL(erfc(p_t(0.4)), p_t(0.57160764495333154489639615468), 10);
  STF_ULP_EQUAL(erfc(bs::Half<p_t>()), p_t(0.479500122186953462317253346108), 15);
  STF_ULP_EQUAL(erfc(bs::One<p_t>()), p_t(0.157299207050285130658779364917), 10);
  STF_ULP_EQUAL(erfc(bs::Two<p_t>()), p_t(0.00467773498104726583793074363275), 10);
  STF_ULP_EQUAL(erfc(bs::Zero<p_t>()), bs::One<r_t>(), 0.5);
  STF_EQUAL(bs::is_less(erfc(p_t(6)), p_t(0.00000000000000003)), bs::True<p_t>());
  STF_EQUAL(bs::is_less(erfc((bs::Ten<p_t>()- p_t(2.088487583762545e-45))), bs::Eps<p_t>()), bs::True<p_t>());
  STF_EQUAL(bs::is_less(erfc(p_t(15))- p_t(7.212994172451206e-100), bs::Eps<p_t>()), bs::True<p_t>());

  STF_ULP_EQUAL(erfc(-p_t(0.1)),        bs::std_(erfc)(-p_t(0.1)),        3.5);
  STF_ULP_EQUAL(erfc(-p_t(0.4)),        bs::std_(erfc)(-p_t(0.4)),        3.5);
  STF_ULP_EQUAL(bs::std_(erfc)(-bs::Half<p_t>()), (erfc)(-bs::Half<p_t>()), 3.5);
  STF_ULP_EQUAL(erfc(-bs::One<p_t>()),  bs::std_(erfc)(-bs::One<p_t>()),  1.5);
  STF_ULP_EQUAL(erfc(-bs::Two<p_t>()),  bs::std_(erfc)(-bs::Two<p_t>()),  1);
  STF_ULP_EQUAL(erfc(p_t(-6)), p_t(2), 0);
}




