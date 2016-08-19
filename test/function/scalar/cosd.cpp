//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cosd.hpp>
#include <boost/simd/function/restricted.hpp>
#include <scalar_test.hpp>
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

STF_CASE_TPL (" cosd bs::restricted_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cosd;

  using r_t = decltype(cosd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::restricted_(cosd)(bs::Inf<T>()),  bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cosd)(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cosd)(bs::Nan<T>()),  bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::restricted_(cosd)(T(-180)),       bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cosd)(T(-45)),        bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cosd)(T(-90)),        bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cosd)(T(180)),        bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cosd)(T(45)),         bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cosd)(T(90)),         bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::restricted_(cosd)(bs::Zero<T>()), bs::One<r_t>(), 0.5);
}
STF_CASE_TPL (" cosd clipped_small",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::cosd;

  using r_t = decltype(cosd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cosd(bs::Inf<T>(), bst::clipped_small_),  bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Minf<T>(), bst::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Nan<T>(), bst::clipped_small_),  bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cosd(T(-180), bst::clipped_small_),       bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-45), bst::clipped_small_),        bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-90), bst::clipped_small_),        bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(180), bst::clipped_small_),        bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(45), bst::clipped_small_),         bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(90), bst::clipped_small_),         bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Zero<T>(), bst::clipped_small_), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" cosd",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bst = bs::tag;
  namespace bd = boost::dispatch;
  using bs::cosd;

  using r_t = decltype(cosd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cosd(bs::Inf<T>(), bst::clipped_medium_),  bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Minf<T>(), bst::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Nan<T>(), bst::clipped_medium_),  bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cosd(T(-180), bst::clipped_medium_),       bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-45), bst::clipped_medium_),        bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(-90), bst::clipped_medium_),        bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(180), bst::clipped_medium_),        bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(45), bst::clipped_medium_),         bs::Sqrt_2o_2<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(T(90), bst::clipped_medium_),         bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cosd(bs::Zero<T>(), bst::clipped_medium_), bs::One<r_t>(), 0.5);
}
