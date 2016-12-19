//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/eps.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/eps.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i< N; ++i)
  {
    a1[i] = T(i);
    b[i] = bs::eps(a1[i]);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);

  STF_IEEE_EQUAL(bs::eps(aa1), bb);
}

STF_CASE_TPL("Check eps on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL ("eps for IEEE types",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::eps;
  using p_t = bs::pack<T>;
  using r_t = decltype(eps(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
 #ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(eps(bs::Inf<p_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(eps(bs::Minf<p_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(eps(bs::Nan<p_t>()), bs::Nan<r_t>());
 #endif

  STF_EQUAL(eps(p_t{-1}), bs::Eps<r_t>());
  STF_EQUAL(eps(p_t{1}) , bs::Eps<r_t>());

 #if !defined(BOOST_SIMD_NO_DENORMALS)
  STF_EQUAL(eps(p_t{0}), bs::Mindenormal<r_t>());
 #endif
}

STF_CASE_TPL ("eps on integers",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::eps;
  using p_t = bs::pack<T>;
  using r_t = decltype(eps(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(eps(p_t(-1)), p_t{1});
  STF_EQUAL(eps(p_t(0)) , p_t{1});
  STF_EQUAL(eps(p_t(-1)), p_t{1});
  STF_EQUAL(eps(p_t(42)), p_t{1});
}
