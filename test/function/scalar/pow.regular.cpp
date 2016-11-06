//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/pow.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
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
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>

STF_CASE_TPL("pow",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using r_t =  decltype(pow(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(pow(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Inf<T>(), bs::Minf<T>()), bs::Zero<r_t>(), 0);
#endif
  STF_ULP_EQUAL(pow(T(-1),T(6)), T(1), 0);
  STF_ULP_EQUAL(pow(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::One<T>(), bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Zero<T>(), bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow(T(-1),T(5)), T(-1), 0);
  STF_ULP_EQUAL(pow(bs::Zero<T>(), bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(pow(T(8),bs::Third<T>()), r_t(2), 0.5);
}

STF_CASE_TPL("powreal_int",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using iT = bd::as_integer_t<T>;
  using r_t =  decltype(pow(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  #ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(pow(bs::Inf<T>(),3), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Minf<T>(),3), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Nan<T>(),3), bs::Nan<r_t>(), 0);
  #endif

  STF_ULP_EQUAL(pow(bs::Two<T>(),-3), (bs::Ratio<r_t, 1, 8>()),  0);
 }

STF_CASE_TPL("powint",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using iT = bd::as_integer_t<T>;
  using r_t =  decltype(pow(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(pow(bs::Mone<T>(),3), bs::Mone<r_t>());
  STF_EQUAL(pow(bs::Mone<T>(),4), bs::One<r_t>());
  STF_EQUAL(pow(bs::One<T>(),3),  bs::One<r_t>());
  STF_EQUAL(pow(bs::Two<T>(),3),  bs::Eight<r_t>());
  STF_EQUAL(pow(bs::Zero<T>(),0), bs::One<r_t>());
  STF_EQUAL(pow(bs::Zero<T>(),3), bs::Zero<r_t>());
}



STF_CASE_TPL("pow conformity",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using r_t =  decltype(pow(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(pow(T(0), T(-1)), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow(-T(0), T(-1)), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(pow(-T(0), T(-2)), bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(T(0), T(-2)), bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(T(0),  bs::Minf<T>()),  bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(-T(0),  bs::Minf<T>()),  bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(-T(1),  bs::Minf<T>()),  bs::One<T>(), 0);
  STF_ULP_EQUAL(pow(-T(1),  bs::Inf <T>()),  bs::One<T>(), 0);
  STF_ULP_EQUAL(pow(T(1), bs::Nan<T>()) ,  bs::One<T>(), 0);
  STF_ULP_EQUAL(pow(bs::Nan<T>(), T(0)) ,  bs::One<T>(), 0);
  STF_ULP_EQUAL(pow(bs::Nan<T>(), -T(0)) ,  bs::One<T>(), 0);
  STF_ULP_EQUAL(pow(T(0.5), bs::Inf<T>()),  bs::Zero<T>(), 0);
  STF_ULP_EQUAL(pow(T(2), bs::Inf<T>()),  bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(T(0.5), bs::Minf<T>()),  bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(T(2), bs::Minf<T>()),  bs::Zero<T>(), 0);
  STF_ULP_EQUAL(pow(-T(0.5), bs::Inf<T>()),  bs::Zero<T>(), 0);
  STF_ULP_EQUAL(pow(-T(2), bs::Inf<T>()),  bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(-T(0.5), bs::Minf<T>()),  bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(-T(2), bs::Minf<T>()),  bs::Zero<T>(), 0);
  STF_ULP_EQUAL(pow(bs::Minf<T>(), T(-3) ),  bs::Mzero<T>(), 0);
  STF_EXPECT(bs::is_negative(pow(bs::Minf<T>(), T(-3) )));
  STF_ULP_EQUAL(pow(bs::Minf<T>(), T(-4) ),  bs::Zero<T>(), 0);
  STF_EXPECT(bs::is_positive(pow(bs::Minf<T>(), T(-4) )));
  STF_ULP_EQUAL(pow(bs::Inf<T>(), T(4) ),  bs::Inf<T>(), 0);
  STF_ULP_EQUAL(pow(bs::Inf<T>(), T(-4) ),  bs::Zero<T>(), 0);
}
