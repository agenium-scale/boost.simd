//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(2*i);
    b[i] = bs::saturated_(bs::unary_minus)(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::saturated_(bs::unary_minus)(aa1), bb);
  STF_IEEE_EQUAL(-aa1, bb);
}

STF_CASE_TPL("Check unary_minus_s on pack" , STF_SIGNED_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}




STF_CASE_TPL( "Check bs::saturated_(bs::unary_minus_s) behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  using r_t = decltype(bs::saturated_(bs::unary_minus)(p_t()));

  STF_TYPE_IS(r_t, p_t);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Inf<p_t>()),  bs::Minf<r_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Minf<p_t>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(bs::saturated_(bs::unary_minus)(bs::Nan<p_t>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Mone<p_t>()), bs::One<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::One<p_t>()), bs::Mone<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmax<p_t>()), bs::Valmin<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmin<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Zero<p_t>()), bs::Zero<p_t>());
}


STF_CASE_TPL( "Check bs::saturated_(bs::unary_minus) behavior with floating", STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  using r_t = decltype(bs::saturated_(bs::unary_minus)(p_t()));

  STF_TYPE_IS(r_t, p_t);

  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Mone<p_t>()), bs::One<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::One<p_t>()), bs::Mone<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmax<p_t>()), bs::Valmin<p_t>()+bs::One<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmin<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Valmin<p_t>()+bs::One<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(bs::saturated_(bs::unary_minus)(bs::Zero<p_t>()), bs::Zero<p_t>());
}





