//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/prev.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/bitincrement.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/mthree.hpp>

STF_CASE_TPL (" prev real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::prev;
  using r_t = decltype(prev(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(prev(bs::Inf<T>()), bs::Valmax<r_t>());
  STF_EQUAL(prev(bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(prev(bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(prev(bs::Valmin<T>()), bs::Minf<r_t>());
#endif
  STF_EQUAL(prev(bs::Mone<T>()), bs::Mone<r_t>()-bs::Eps<r_t>());
  STF_EQUAL(prev(bs::One<T>()), bs::One<r_t>()-bs::Eps<r_t>()/2);
  STF_EQUAL(prev(bs::Zero<T>()), -bs::Bitincrement<T>());
}

STF_CASE_TPL (" prev unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::prev;
  using r_t = decltype(prev(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(prev(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(prev(bs::Valmin<T>()), bs::Valmax<r_t>());
  STF_EQUAL(prev(bs::Zero<T>()), bs::Valmax<r_t>());
}

STF_CASE_TPL (" prev signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::prev;
  using r_t = decltype(prev(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(prev(bs::Mone<T>()), -bs::Two<r_t>());
  STF_EQUAL(prev(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(prev(bs::Zero<T>()), bs::Mone<r_t>());
}
