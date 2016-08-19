//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sinhcosh.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/function/cosh.hpp>
#include <boost/simd/function/sinh.hpp>

STF_CASE_TPL("sinhcosh", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sinhcosh;

  T a[] = {bs::Zero<T>(), bs::One<T>(), T(5), T(-5)};
  size_t N =  sizeof(a)/sizeof(T);
  STF_EXPR_IS( (sinhcosh(T()))
                  , (std::pair<T,T>)
                  );

  {
    for(size_t i=0; i < N; ++i)
    {
      std::pair<T,T> p = sinhcosh(a[i]);
      STF_ULP_EQUAL(p.first,  bs::sinh(a[i]), 1);
      STF_ULP_EQUAL(p.second, bs::cosh(a[i]), 1);
    }
  }

  T b[] = {bs::Inf<T>(), bs::Minf<T>(), bs::Nan<T>()};
  N =  sizeof(b)/sizeof(T);
#ifndef BOOST_SIMD_NO_INVALIDS

  {
    for(size_t i=0; i < N; ++i)
    {
      std::pair<T,T> p = sinhcosh(b[i]);
      STF_ULP_EQUAL(p.first,  bs::sinh(b[i]), 1);
      STF_ULP_EQUAL(p.second, bs::cosh(b[i]), 1);
    }
  }
#endif
}
