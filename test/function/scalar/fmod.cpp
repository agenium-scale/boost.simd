//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/fmod.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/fast.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <cmath>

STF_CASE_TPL (" fmod real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmod;
  using r_t = decltype(fmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(fmod(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(fmod(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(fmod(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(fmod(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(fmod(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(fmod(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<T>());
} // end of test for floating_

STF_CASE_TPL (" fmod real fast",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmod;
  using r_t = decltype(fmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(bs::fast_(fmod)(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(bs::fast_(fmod)(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(bs::fast_(fmod)(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(bs::fast_(fmod)(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(bs::fast_(fmod)(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
} // end of test for floating_

STF_CASE_TPL (" fmod unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmod;
  using r_t = decltype(fmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(fmod(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(fmod(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" fmod signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmod;
  using r_t = decltype(fmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(fmod(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(fmod(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(fmod(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL (" fmod limits",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmod;
  using r_t = decltype(fmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(fmod(T(0), T(1)),  T(0));
  STF_EQUAL(fmod(-T(0), T(1)),  T(-0));
  STF_EXPECT(bs::is_negative(fmod(-T(0), T(1))));
  STF_EXPECT(bs::is_positive(fmod(T(0), T(1))));
  STF_IEEE_EQUAL(fmod(bs::Inf<T>(), T(1)),  bs::Nan<T>());
  STF_IEEE_EQUAL(fmod(bs::Minf<T>(), T(1)), bs::Nan<T>());
  STF_IEEE_EQUAL(fmod(T(1), T(0)),  bs::Nan<T>());
  STF_IEEE_EQUAL(fmod(T(1), T(-0)), bs::Nan<T>());
  STF_EQUAL(fmod(T(2), bs::Inf<T>()), T(2));
  STF_EQUAL(fmod(T(2), bs::Minf<T>()), T(2));

}

STF_CASE_TPL (" fmod std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::fmod;
  using r_t = decltype(fmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(bs::std_(fmod)(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(bs::std_(fmod)(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(bs::std_(fmod)(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(bs::std_(fmod)(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(bs::std_(fmod)(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(bs::std_(fmod)(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<T>());
} // end of
