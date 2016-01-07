//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/sqrt.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/options.hpp>

STF_CASE_TPL (" sqrt real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt;
  using r_t = decltype(sqrt(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_ULP_EQUAL(sqrt(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(sqrt(bs::Mone<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Two<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sqrt(bs::Zero<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Mzero<T>()), bs::Mzero<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Four<T>()), bs::Two<r_t>(), 0);
  STF_EXPECT(bs::is_negative(sqrt(bs::Mzero<T>())));
  STF_EXPECT(bs::is_positive(sqrt(bs::Zero<T>())));
} // end of test for floating_


STF_CASE_TPL (" sqrt si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt;
  using r_t = decltype(sqrt(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sqrt(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(sqrt(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(sqrt(bs::Two<T>()), bs::One<r_t>());
  STF_EQUAL(sqrt(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(sqrt(bs::Four<T>()), bs::Two<r_t>());
} // end of test for floating_


STF_CASE_TPL (" sqrt ui",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt;

  using r_t = decltype(sqrt(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sqrt(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(sqrt(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(sqrt(bs::Two<T>()), bs::One<r_t>());
  STF_EQUAL(sqrt(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(sqrt(bs::Four<T>()), bs::Two<r_t>());
} // end of test for floating_


STF_CASE_TPL (" sqrt real fast",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt;
  using r_t = decltype(sqrt(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_ULP_EQUAL(sqrt(bs::Minf<T>(), bs::fast_), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Nan<T>(), bs::fast_), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(sqrt(bs::Mone<T>(), bs::fast_), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::One<T>(), bs::fast_), bs::One<r_t>(), 20);
  STF_ULP_EQUAL(sqrt(bs::Two<T>(), bs::fast_), bs::Sqrt_2<r_t>(), 1);
  STF_ULP_EQUAL(sqrt(bs::Zero<T>(), bs::fast_), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Four<T>(), bs::fast_), bs::Two<r_t>(), 20);
} // end of test for floating_

STF_CASE_TPL (" sqrt std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrt;
  using r_t = decltype(sqrt(T(), bs::std_));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_ULP_EQUAL(bs::sqrt(bs::Inf<T>(), bs::std_), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Minf<T>(), bs::std_), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Nan<T>(), bs::std_), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(sqrt(bs::Mone<T>(), bs::std_), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::One<T>(), bs::std_), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Two<T>(), bs::std_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sqrt(bs::Zero<T>(), bs::std_), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Mzero<T>(), bs::std_), bs::Mzero<r_t>(), 0);
  STF_ULP_EQUAL(sqrt(bs::Four<T>(), bs::std_), bs::Two<r_t>(), 0);
  STF_EXPECT(bs::is_negative(sqrt(bs::Mzero<T>(), bs::std_)));
  STF_EXPECT(bs::is_positive(sqrt(bs::Zero<T>(), bs::std_)));
} // end of test for floating_
