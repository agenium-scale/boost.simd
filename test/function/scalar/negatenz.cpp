//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/negatenz.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/mthree.hpp>


STF_CASE_TPL (" negatenz real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::negatenz;
  using r_t = decltype(negatenz(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(negatenz(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(negatenz(bs::Minf<T>(), bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(negatenz(bs::Nan<T>(), bs::Zero<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(negatenz(bs::Nan<T>(), bs::Zero<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(negatenz(bs::Nan<T>(), bs::One<T>()), bs::Nan<r_t>());
#endif
  STF_TYPE_IS(r_t, T);
  STF_EQUAL(negatenz(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(negatenz(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(negatenz(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(negatenz(bs::One<T>(), bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(negatenz(bs::Two<T>(), bs::Mthree<T>()), bs::Mtwo<r_t>());
  STF_EQUAL(negatenz(bs::Two<T>(), bs::Three<T>()), bs::Two<r_t>());
}

STF_CASE_TPL (" negatenz unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::negatenz;
  using r_t = decltype(negatenz(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_TYPE_IS(r_t, T);
  STF_EQUAL(negatenz(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(negatenz(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(negatenz(bs::One<T>(), bs::Zero<T>()), bs::One<r_t>());
}

STF_CASE_TPL (" negatenz signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::negatenz;
  using r_t = decltype(negatenz(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_TYPE_IS(r_t, T);
  STF_EQUAL(negatenz(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(negatenz(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(negatenz(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(negatenz(bs::One<T>(), bs::Zero<T>()), bs::One<r_t>());
}
