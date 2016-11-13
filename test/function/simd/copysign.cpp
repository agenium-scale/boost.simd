//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>


template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::copysign(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::copysign(aa1, aa2), bb);
}

STF_CASE_TPL("Check copysign on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL (" copysign real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::copysign;
  using p_t = bs::pack<T>;
  using r_t = decltype(copysign(p_t(), p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(copysign(bs::Inf<p_t>(), bs::Inf<p_t>()), bs::Inf<r_t>());
  STF_EQUAL(copysign(bs::Minf<p_t>(), bs::Minf<p_t>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(copysign(bs::Nan<p_t>(), bs::Nan<p_t>()), bs::Nan<r_t>());
  STF_EQUAL(copysign(bs::Inf<p_t>(), bs::Minf<p_t>()), bs::Minf<r_t>());
  STF_EQUAL(copysign(bs::Minf<p_t>(), bs::Inf<p_t>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(copysign(bs::Nan<p_t>(), bs::Inf<p_t>()), bs::Nan<r_t>());
  STF_EQUAL(copysign(bs::One<p_t>(), bs::Nan<p_t>()), bs::Mone<r_t>());
#endif
  STF_EQUAL(copysign(bs::Mone<p_t>(), bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(copysign(bs::One<p_t>(), bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(copysign(bs::One<p_t>(), bs::Mzero<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(copysign(bs::One<p_t>(), bs::Zero<p_t>()), bs::One<r_t>());
  STF_EQUAL(copysign(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" copysign signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::copysign;
  using p_t = bs::pack<T>;
  using r_t = decltype(copysign(p_t(), p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(copysign(bs::Mone<p_t>(), bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(copysign(bs::One<p_t>(), bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(copysign(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(copysign(bs::Mone<p_t>(), bs::One<p_t>()), bs::One<r_t>());
  STF_EQUAL(copysign(bs::One<p_t>(), bs::Mone<p_t>()), bs::Mone<r_t>());
  STF_EQUAL(copysign(bs::Mone<p_t>(), bs::Zero<p_t>()), bs::One<r_t>());
}
