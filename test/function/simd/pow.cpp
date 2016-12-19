//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/pow.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eight.hpp>
#include <boost/simd/constant/third.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>

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
     b[i] = bs::pow(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::pow(aa1, aa2), bb);

}

STF_CASE_TPL("Check pow on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL("pow",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using p_t = bs::pack<T>;
  using r_t =  decltype(pow(p_t(), p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(pow(bs::Inf<p_t>(), bs::Inf<p_t>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Nan<p_t>(), bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Minf<p_t>(), bs::Minf<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Inf<p_t>(), bs::Minf<p_t>()), bs::Zero<r_t>(), 0);
#endif
  STF_ULP_EQUAL(pow(p_t(-1),p_t(6)), p_t(1), 0);
  STF_ULP_EQUAL(pow(bs::Mone<p_t>(), bs::Mone<p_t>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::One<p_t>(), bs::One<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Zero<p_t>(), bs::Zero<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow(p_t(-1),p_t(5)), p_t(-1), 0);
  STF_ULP_EQUAL(pow(bs::Zero<p_t>(), bs::One<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(pow(p_t(8),bs::Third<p_t>()), r_t(2), 0.5);
}

STF_CASE_TPL("powreal_int",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using p_t = bs::pack<T>;
  using ip_t = bd::as_integer_t<p_t>;
  using r_t =  decltype(pow(p_t(), ip_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  #ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(pow(bs::Inf<p_t>(),3), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Minf<p_t>(),3), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Nan<p_t>(),3), bs::Nan<r_t>(), 0);
  #endif

  STF_ULP_EQUAL(pow(bs::Two<p_t>(),-3), (bs::Ratio<r_t, 1, 8>()),  0);
 }


STF_CASE_TPL("pow conformity",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using p_t = bs::pack<T>;
  using r_t =  decltype(pow(p_t(), p_t()));

  // return type conformity test
   STF_TYPE_IS(r_t, p_t);

  // specific values tests
   STF_ULP_EQUAL(pow(p_t(0), p_t(-1)), bs::Inf<r_t>(), 0);
   STF_ULP_EQUAL(pow(-p_t(0), p_t(-1)), bs::Minf<r_t>(), 0);
   STF_ULP_EQUAL(pow(-p_t(0), p_t(-2)), bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(p_t(0), p_t(-2)), bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(p_t(0),  bs::Minf<p_t>()),  bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(-p_t(0),  bs::Minf<p_t>()),  bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(-p_t(1),  bs::Minf<p_t>()),  bs::One<p_t>(), 0);
   STF_ULP_EQUAL(pow(-p_t(1),  bs::Inf <p_t>()),  bs::One<p_t>(), 0);
   STF_ULP_EQUAL(pow(p_t(1), bs::Nan<p_t>()) ,  bs::One<p_t>(), 0);
   STF_ULP_EQUAL(pow(bs::Nan<p_t>(), p_t(0)) ,  bs::One<p_t>(), 0);
   STF_ULP_EQUAL(pow(bs::Nan<p_t>(), -p_t(0)) ,  bs::One<p_t>(), 0);
   STF_ULP_EQUAL(pow(p_t(0.5), bs::Inf<p_t>()),  bs::Zero<p_t>(), 0);
   STF_ULP_EQUAL(pow(p_t(2), bs::Inf<p_t>()),  bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(p_t(0.5), bs::Minf<p_t>()),  bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(p_t(2), bs::Minf<p_t>()),  bs::Zero<p_t>(), 0);
   STF_ULP_EQUAL(pow(-p_t(0.5), bs::Inf<p_t>()),  bs::Zero<p_t>(), 0);

   STF_ULP_EQUAL(pow(-p_t(2), bs::Inf<p_t>()),  bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(-p_t(0.5), bs::Minf<p_t>()),  bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(-p_t(2), bs::Minf<p_t>()),  bs::Zero<p_t>(), 0);
   STF_ULP_EQUAL(pow(bs::Minf<p_t>(), p_t(-3) ),  bs::Mzero<p_t>(), 0);
   STF_EQUAL(bs::is_negative(pow(bs::Minf<p_t>(), p_t(-3) )), bs::True<p_t>());
   STF_ULP_EQUAL(pow(bs::Minf<p_t>(), p_t(-4) ),  bs::Zero<p_t>(), 0);
   STF_EQUAL(bs::is_positive(pow(bs::Minf<p_t>(), p_t(-4) )), bs::True<p_t>());
   STF_ULP_EQUAL(pow(bs::Inf<p_t>(), p_t(4) ),  bs::Inf<p_t>(), 0);
   STF_ULP_EQUAL(pow(bs::Inf<p_t>(), p_t(-4) ),  bs::Zero<p_t>(), 0);
}
