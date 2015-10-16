//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/saturate_at.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>

// STF_CASE_TPL (" saturate_atreal",  STF_IEEE_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::saturate_at;

//   using bs::Pi;
//   using r_t = decltype(saturate_at<bs::tag::Pi>(T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
// #ifndef STF_NO_INVALIDS
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Inf<T>()), bs::Pi<r_t>(), 0);
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Minf<T>()), -bs::Pi<r_t>(), 0);
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Nan<T>()), bs::Nan<r_t>(), 0);
// #endif
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Mone<T>()), bs::Mone<r_t>(), 0);
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::One<T>()), bs::One<r_t>(), 0);
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Zero<T>()), bs::Zero<r_t>(), 0);
// }

// STF_CASE_TPL (" saturate_atsigned_int",  STF_SIGNED_ALL_INTEGRAL_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::saturate_at;

//   using bs::tag::Pi;
//   using r_t = decltype(saturate_at<Pi>(T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t,T);

//   // specific values tests
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Mone<T>()), bs::Mone<r_t>(), 0);
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::One<T>()), bs::One<r_t>(), 0);
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Valmax<T>()), bs::Pi<r_t>(), 0);
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Valmin<T>()), -bs::Pi<r_t>(), 0);
//   STF_ULP_EQUAL(saturate_at<Pi>(bs::Zero<T>()), bs::Zero<r_t>(), 0);
// }

