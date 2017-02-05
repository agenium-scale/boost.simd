//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/significants.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using iT =  bd::as_integer_t<T>;
  using p_t = bs::pack<T, N>;
  using pi_t= bs::pack<iT, N>;

  T a1[N], b[N];
  iT a2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : bs::rec(T(i));
    a2[i] = i+2;
    b[i] = bs::significants(a1[i], a2[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  pi_t aa2(&a2[0], &a2[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_ULP_EQUAL(bs::significants(aa1, aa2), bb, 0.5);
}

STF_CASE_TPL("Check significants on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}




STF_CASE_TPL (" significants",  (float))//STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::significants;
  using p_t = bs::pack<T>;

  using ip_t =  bd::as_integer_t<p_t>;
  using r_t = decltype(significants(p_t(), ip_t()));

  // return type conformity test
  STF_TYPE_IS( r_t, p_t );

#ifndef BOOST_SIMD_NO_INVALIDS
   STF_ULP_EQUAL(significants(bs::Inf<p_t>(), ip_t(1)), bs::Inf<r_t>(), 0.5);
   STF_ULP_EQUAL(significants(bs::Minf<p_t>(), ip_t(1)), bs::Minf<r_t>(), 0.5);
   STF_ULP_EQUAL(significants(bs::Nan<p_t>(),ip_t(1)), bs::Nan<r_t>(), 0.5);
#endif
   STF_ULP_EQUAL(significants(p_t(0), ip_t(1)), p_t(0), 0.5);
   STF_ULP_EQUAL(significants(p_t(25.34), ip_t(1)), p_t(30), 0.5);
   STF_ULP_EQUAL(significants(p_t(25.34), ip_t(2)), p_t(25), 0.5);
   STF_ULP_EQUAL(significants(p_t(25.34), ip_t(3)), p_t(25.3), 0.5);
   STF_ULP_EQUAL(significants(p_t(25.34), ip_t(4)), p_t(25.34), 0.5);
   STF_ULP_EQUAL(significants(p_t(-25.34), ip_t(1)), p_t(-30), 0.5);
   STF_ULP_EQUAL(significants(p_t(-25.34),ip_t(2)), p_t(-25), 0.5);
   STF_ULP_EQUAL(significants(p_t(-25.34), ip_t(3)), p_t(-25.3), 0.5);
   STF_ULP_EQUAL(significants(p_t(-25.34), ip_t(4)), p_t(-25.34), 0.5);
   STF_ULP_EQUAL(significants(p_t(-25.34), 4), p_t(-25.34), 0.5);
}
