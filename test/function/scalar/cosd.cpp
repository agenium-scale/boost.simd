//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/cosd.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>


STF_CASE_TPL (" cosd",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cosd;

  using r_t = decltype(cosd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cosd(bs::Inf<T>()),  bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Nan<T>()),  bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cosd(T(-180)),       bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-45)),        bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-90)),        bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(180)),        bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(45)),         bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(90)),         bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Zero<T>()), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" cosd bs::fast_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cosd;

  using r_t = decltype(cosd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cosd(bs::Inf<T>(), bs::fast_),  bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Minf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Nan<T>(), bs::fast_),  bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cosd(T(-180), bs::fast_),       bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-45), bs::fast_),        bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-90), bs::fast_),        bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(180), bs::fast_),        bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(45), bs::fast_),         bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(90), bs::fast_),         bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Zero<T>(), bs::fast_), bs::One<r_t>(), 0.5);
}
STF_CASE_TPL (" cosd clipped_small",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cosd;

  using r_t = decltype(cosd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cosd(bs::Inf<T>(), bs::clipped_small_),  bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Minf<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Nan<T>(), bs::clipped_small_),  bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cosd(T(-180), bs::clipped_small_),       bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-45), bs::clipped_small_),        bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-90), bs::clipped_small_),        bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(180), bs::clipped_small_),        bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(45), bs::clipped_small_),         bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(90), bs::clipped_small_),         bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Zero<T>(), bs::clipped_small_), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" cosd",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cosd;

  using r_t = decltype(cosd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cosd(bs::Inf<T>(), bs::clipped_medium_),  bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Minf<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Nan<T>(), bs::clipped_medium_),  bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cosd(T(-180), bs::clipped_medium_),       bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-45), bs::clipped_medium_),        bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-90), bs::clipped_medium_),        bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(180), bs::clipped_medium_),        bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(45), bs::clipped_medium_),         bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(90), bs::clipped_medium_),         bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Zero<T>(), bs::clipped_medium_), bs::One<r_t>(), 0.5);
}
