//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/dist.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/mten.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/ratio.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::dist(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::dist(aa1, aa2), bb);
}

STF_CASE_TPL("Check dist on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void tests(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    a2[i] = (i%2) ? T(i+N) : T(-(i+N));
    b[i] = bs::saturated_(bs::dist)(a1[i], a2[i]);
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::saturated_(bs::dist)(aa1, aa2), bb);
}

STF_CASE_TPL("Check dist on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}


STF_CASE_TPL (" dist real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::dist;
  using p_t = bs::pack<T>;

  STF_EXPR_IS( dist(p_t(), p_t()), p_t );

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(dist(bs::Inf<p_t>() , bs::Inf<p_t>()) , bs::Nan<p_t>());
  STF_IEEE_EQUAL(dist(bs::Minf<p_t>(), bs::Minf<p_t>()), bs::Nan<p_t>());
  STF_IEEE_EQUAL(dist(bs::Nan<p_t>() , bs::Nan<p_t>()) , bs::Nan<p_t>());
#endif

  STF_EQUAL(dist(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(dist(bs::Mone<p_t>(), bs::One<p_t>()), bs::Two<p_t>());
  STF_EQUAL(dist(bs::One<p_t>(), bs::Three<p_t>()), bs::Two<p_t>());
}

STF_CASE_TPL (" dist integer_ui",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::dist;
  using p_t = bs::pack<T>;

  STF_EXPR_IS( dist(p_t(), p_t()), p_t );

  STF_EQUAL(dist(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(dist(bs::One<p_t>(), bs::Three<p_t>()), bs::Two<p_t>());
  STF_EQUAL(dist(bs::Valmax<p_t>(), bs::Zero<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(dist(bs::Zero<p_t>(), bs::Valmax<p_t>()), bs::Valmax<p_t>());
}

STF_CASE_TPL (" dist integer_si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::dist;
  using p_t = bs::pack<T>;
  STF_EXPR_IS( dist(p_t(), p_t()), p_t );

  STF_EQUAL(dist(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(dist(bs::Mone<p_t>(), bs::One<p_t>()), bs::Two<p_t>());
  STF_EQUAL(dist(bs::One<p_t>(), bs::Three<p_t>()), bs::Two<p_t>());
  STF_EQUAL(dist(bs::Valmax<p_t>(), bs::Zero<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(dist(bs::Zero<p_t>(), bs::Valmax<p_t>()), bs::Valmax<p_t>());
  STF_EQUAL(dist(bs::Zero<p_t>(), bs::Valmin<p_t>()), bs::Valmin<p_t>());

  STF_EQUAL(dist(bs::Ten<p_t>(), bs::Mten<p_t>()), (p_t(20)));
  STF_EQUAL(dist(bs::Mten<p_t>(), bs::Ten<p_t>()), (p_t(20)));
}

