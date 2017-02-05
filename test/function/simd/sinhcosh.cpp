//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/function/sinhcosh.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/function/cosh.hpp>
#include <boost/simd/function/sinh.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N], c[N], s[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i)/2 : -T(i)/2;
    std::tie(s[i], c[i])= bs::sinhcosh(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t ss (&s[0], &s[0]+N);
  p_t cc (&c[0], &c[0]+N);
  p_t ss1, cc1;
  std::tie(ss1, cc1)= bs::sinhcosh(aa1) ;
  STF_ULP_EQUAL(ss1, ss, 0.5);
  STF_ULP_EQUAL(cc1, cc, 0.5);
}

STF_CASE_TPL("Check sincosh on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL("sinhcosh", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T>;
  using bs::sinhcosh;

  p_t a[] = {bs::Zero<p_t>(), bs::One<p_t>(), p_t(5), p_t(-5)};
  size_t N =  sizeof(a)/sizeof(p_t);
  STF_EXPR_IS( (sinhcosh(p_t()))
                  , (std::pair<p_t,p_t>)
                  );

  {
    for(size_t i=0; i < N; ++i)
    {
      std::pair<p_t,p_t> p = sinhcosh(a[i]);
      STF_ULP_EQUAL(p.first,  bs::sinh(a[i]), 1);
      STF_ULP_EQUAL(p.second, bs::cosh(a[i]), 1);
    }
  }

#ifndef BOOST_SIMD_NO_INVALIDS
  p_t b[] = {bs::Inf<p_t>(), bs::Minf<p_t>(), bs::Nan<p_t>()};
  N =  sizeof(b)/sizeof(p_t);

  {
    for(size_t i=0; i < N; ++i)
    {
      std::pair<p_t,p_t> p = sinhcosh(b[i]);
      STF_ULP_EQUAL(p.first,  bs::sinh(b[i]), 1);
      STF_ULP_EQUAL(p.second, bs::cosh(b[i]), 1);
    }
  }
#endif
}
