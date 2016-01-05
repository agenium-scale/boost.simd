//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/atan.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/options.hpp>

STF_CASE_TPL (" atan",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atan;

  using r_t = decltype(atan(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(atan(bs::Inf<T>()), bs::Pio_2<r_t>(), 0);
  STF_ULP_EQUAL(atan(bs::Minf<T>()), -bs::Pio_2<r_t>(), 0);
  STF_ULP_EQUAL(atan(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(atan(bs::Half<T>()), T(4.636476090008061e-01), 0.5);
  STF_ULP_EQUAL(atan(bs::Mhalf<T>()), T(-4.636476090008061e-01), 0.5);
  STF_ULP_EQUAL(atan(bs::Mone<T>()), -bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan(bs::One<T>()), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan(bs::Mzero<T>()), bs::Mzero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(atan(bs::Mzero<T>())));
  STF_EXPECT(bs::is_positive(atan(bs::Zero<T>())));
}
STF_CASE_TPL (" atan std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atan;

  using r_t = decltype(atan(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(atan(bs::Inf<T>(), bs::std_), bs::Pio_2<r_t>(), 0);
  STF_ULP_EQUAL(atan(bs::Minf<T>(), bs::std_), -bs::Pio_2<r_t>(), 0);
  STF_ULP_EQUAL(atan(bs::Nan<T>(), bs::std_), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(atan(bs::Half<T>(), bs::std_), T(4.636476090008061e-01), 0.5);
  STF_ULP_EQUAL(atan(bs::Mhalf<T>(), bs::std_), T(-4.636476090008061e-01), 0.5);
  STF_ULP_EQUAL(atan(bs::Mone<T>(), bs::std_), -bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan(bs::One<T>(), bs::std_), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan(bs::Zero<T>(), bs::std_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan(bs::Mzero<T>(), bs::std_), bs::Mzero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(atan(bs::Mzero<T>(), bs::std_)));
  STF_EXPECT(bs::is_positive(atan(bs::Zero<T>(), bs::std_)));
}
