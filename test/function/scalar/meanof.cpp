//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/meanof.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" meanof real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::meanof;

  using r_t = decltype(meanof(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(meanof(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(meanof(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(meanof(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(meanof(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(meanof(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(meanof(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(meanof(bs::Inf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_EQUAL(meanof(bs::Valmax<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(meanof(bs::Valmin<T>(), bs::Valmin<T>()), bs::Valmin<T>());
  STF_EQUAL(meanof(bs::Valmax<T>()/2, bs::Valmax<T>()), bs::Valmax<T>()*T(0.75));
  STF_EQUAL(meanof(bs::Valmin<T>()/2, bs::Valmin<T>()), bs::Valmin<T>()*T(0.75));
  STF_EQUAL(meanof(bs::Valmax<T>()/2, bs::Valmax<T>()), bs::Valmax<T>()*T(0.75));
  STF_EQUAL(meanof(bs::Valmin<T>()/2, bs::Valmin<T>()), bs::Valmin<T>()*T(0.75));
} // end of test for floating_

STF_CASE_TPL (" meanof signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::meanof;
  using r_t = decltype(meanof(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(meanof(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(meanof(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(meanof(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(meanof(bs::Valmax<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(meanof(bs::Valmin<T>(), bs::Valmin<T>()), bs::Valmin<T>());
  STF_EQUAL(meanof(T((bs::Valmax<T>()-T(3))/T(2)), T(bs::Valmax<T>()-T(3))), ((bs::Valmax<T>()-T(3))/T(4))*T(3));
  STF_EQUAL(meanof(T((bs::Valmin<T>())/T(2)), bs::Valmin<T>()), (bs::Valmin<T>()/T(4))*T(3));
} // end of test for signed_int_

STF_CASE_TPL (" meanof unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::meanof;
  using r_t = decltype(meanof(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(meanof(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(meanof(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(meanof(bs::Valmax<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(meanof(bs::Valmin<T>(), bs::Valmin<T>()), bs::Valmin<T>());
  STF_EQUAL(meanof(T((bs::Valmax<T>()-T(3))/T(2)), T(bs::Valmax<T>()-T(3))), ((bs::Valmax<T>()-T(3))/T(4))*T(3));
  STF_EQUAL(meanof(T((bs::Valmin<T>())/T(2)), bs::Valmin<T>()), (bs::Valmin<T>()/T(4))*T(3));
} // end of test for unsigned_int_
