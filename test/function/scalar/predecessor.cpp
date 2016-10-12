//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/predecessor.hpp>
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

STF_CASE_TPL (" predecessor real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::predecessor;
  using r_t = decltype(predecessor(T()));

  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(predecessor(bs::Inf<T>()), bs::Valmax<r_t>());
  STF_IEEE_EQUAL(predecessor(bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(predecessor(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(predecessor(bs::Mone<T>()), bs::Mone<r_t>()-bs::Eps<r_t>());
  STF_EQUAL(predecessor(bs::One<T>()), bs::One<r_t>()-bs::Halfeps<r_t>());
  STF_EQUAL(predecessor(bs::Valmin<T>()), bs::Minf<r_t>());
#if !defined(BOOST_SIMD_NO_DENORMALS)
  STF_EQUAL(predecessor(bs::Zero<T>()), -bs::Bitincrement<T>());
#endif
} // end of test for floating_

STF_CASE_TPL (" predecessor ui ",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::predecessor;
  using r_t = decltype(predecessor(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(predecessor(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(predecessor(bs::Valmin<T>()), bs::Valmin<r_t>());
  STF_EQUAL(predecessor(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" predecessor si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::predecessor;

  using r_t = decltype(predecessor(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(predecessor(bs::Mone<T>()), -bs::Two<r_t>());
  STF_EQUAL(predecessor(bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(predecessor(bs::Valmin<T>()), bs::Valmin<r_t>());
  STF_EQUAL(predecessor(bs::Zero<T>()), bs::Mone<r_t>());
} // end of test for signed_int_

STF_CASE_TPL (" predecessor real 2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::predecessor;

  using iT = bd::as_integer_t<T>;
  using r_t = decltype(predecessor(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(predecessor(bs::Minf<T>(), bs::Two<iT>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(predecessor(bs::Nan<T>(), bs::Two<iT>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(predecessor(bs::Mone<T>(), bs::Two<iT>()), bs::Mone<r_t>()-bs::Eps<r_t>()-bs::Eps<r_t>());
  STF_EQUAL(predecessor(bs::One<T>(), bs::Two<iT>()), bs::One<r_t>()-bs::Eps<r_t>());
  STF_IEEE_EQUAL(predecessor(bs::Valmin<T>(), bs::Two<iT>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(predecessor(bs::Valmin<T>(), bs::Four<iT>()), bs::Nan<r_t>());
#if !defined(BOOST_SIMD_NO_DENORMALS)
  STF_EQUAL(predecessor(bs::Zero<T>(), bs::Two<iT>()), -bs::Bitincrement<r_t>()-bs::Bitincrement<r_t>());
#endif
}

STF_CASE_TPL (" predecessorui_2",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::predecessor;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(predecessor(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);
  STF_EQUAL(predecessor(bs::Four<T>(), bs::Two<iT>()), bs::Two<r_t>());
  STF_EQUAL(predecessor(bs::One<T>(), bs::Two<iT>()), bs::Zero<r_t>());
  STF_EQUAL(predecessor(bs::Valmin<T>(), bs::Two<iT>()), bs::Valmin<r_t>());
  STF_EQUAL(predecessor(bs::Valmin<T>(), bs::Four<iT>()), bs::Valmin<r_t>());
}

STF_CASE_TPL (" predecessorsi_2",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::predecessor;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(predecessor(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);
  STF_EQUAL(predecessor(bs::Mone<T>(), bs::Two<iT>()), bs::Mthree<r_t>());
  STF_EQUAL(predecessor(bs::One<T>(), bs::Two<iT>()), bs::Mone<r_t>());
  STF_EQUAL(predecessor(bs::Valmin<T>(), bs::Two<iT>()), bs::Valmin<r_t>());
  STF_EQUAL(predecessor(bs::Valmin<T>(), bs::Four<iT>()), bs::Valmin<r_t>());
} // end of test for signed_int_
