//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/exp10.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/function/is_flint.hpp>

STF_CASE_TPL ("exp10",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::exp10;
  using r_t = decltype(exp10(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(exp10(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(exp10(bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(exp10(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(exp10(bs::Mone<T>()), (bs::Ratio<r_t, 1, 10>()), 0.75);
  STF_ULP_EQUAL(exp10(bs::One<T>()), bs::Ten<r_t>(), 0.75);
  STF_ULP_EQUAL(exp10(bs::Zero<T>()), bs::One<r_t>(), 0.75);

  for(int i=0; i < 30 ; i++)
  {
    STF_EXPECT(bs::is_flint(exp10(T(i))));
  }
}


