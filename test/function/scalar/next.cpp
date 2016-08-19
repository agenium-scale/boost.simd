//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/next.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/bitincrement.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" next real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::next;
  using r_t = decltype(next(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(next(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(next(bs::Minf<T>()), bs::Valmin<r_t>());
  STF_IEEE_EQUAL(next(bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(next(bs::Valmax<T>()), bs::Inf<r_t>());
#endif
  STF_EQUAL(next(bs::Mone<T>()), bs::Mone<r_t>()+bs::Eps<r_t>()/2);
  STF_EQUAL(next(bs::One<T>()), bs::One<r_t>()+bs::Eps<r_t>());
  STF_EQUAL(next(bs::Zero<T>()), bs::Bitincrement<T>());
}

STF_CASE_TPL (" next unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::next;
  using r_t = decltype(next(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(next(bs::One<T>()), bs::Two<r_t>());
  STF_EQUAL(next(bs::Valmax<T>()), bs::Valmin<r_t>());
  STF_EQUAL(next(bs::Zero<T>()), bs::One<r_t>());
}

STF_CASE_TPL (" next signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::next;
  using r_t = decltype(next(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(next(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(next(bs::One<T>()), bs::Two<r_t>());
  STF_EQUAL(next(bs::Zero<T>()), bs::One<r_t>());
}
