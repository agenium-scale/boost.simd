//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/tenpower.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/ratio.hpp>


STF_CASE_TPL (" tenpower unsigned_int", STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tenpower;
  using r_t = decltype(tenpower(T()));

  STF_TYPE_IS(r_t, bd::as_floating_t<T>);

  // specific values tests
  STF_ULP_EQUAL(tenpower(bs::One<T>()), (bs::Ratio<T, 10>()), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Two<T>()), (bs::Ratio<T, 100>()), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Zero<T>()), bs::One<r_t>(), 0.5);
} // end of test for unsigned_int_

STF_CASE_TPL (" tenpower signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::tenpower;
  using r_t = decltype(tenpower(T()));

  STF_TYPE_IS(r_t, bd::as_floating_t<T>);


  // specific values tests
  STF_ULP_EQUAL(tenpower(bs::Mone<T>()), (bs::Ratio<r_t, 1, 10>()), 0.5);
  STF_ULP_EQUAL(tenpower(bs::One<T>()), bs::Ten<r_t>(), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Two<T>()), (bs::Ratio<T, 100>()), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Mtwo<T>()), (bs::Ratio<r_t, 1, 100>()), 0.5);
  STF_ULP_EQUAL(tenpower(bs::Zero<T>()), bs::One<r_t>(), 0.5);
} // end of test for signed_int_
