//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/successor.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/bitincrement.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" successor real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using r_t = decltype(successor(T()));

  // specific values tests
  STF_IEEE_EQUAL(successor(bs::Inf<T>()), bs::Nan<r_t>());
  STF_EQUAL(successor(bs::Minf<T>()), bs::Valmin<r_t>());
  STF_EQUAL(successor(bs::Mone<T>()), bs::Mone<r_t>()+bs::Eps<r_t>()/2);
  STF_IEEE_EQUAL(successor(bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(successor(bs::One<T>()), bs::One<r_t>()+bs::Eps<r_t>());
  STF_EQUAL(successor(bs::Valmax<T>()), bs::Inf<r_t>());
  STF_EQUAL(successor(bs::Zero<T>()), bs::Bitincrement<T>());
} // end of test for floating_

STF_CASE_TPL (" successor unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using r_t = decltype(successor(T()));

  // specific values tests
  STF_EQUAL(successor(bs::One<T>()), bs::Two<r_t>());
  STF_EQUAL(successor(bs::Valmax<T>()), bs::Valmax<r_t>());
  STF_EQUAL(successor(bs::Zero<T>()), bs::One<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" successor signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using r_t = decltype(successor(T()));

  // specific values tests
  STF_EQUAL(successor(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(successor(bs::One<T>()), bs::Two<r_t>());
  STF_EQUAL(successor(bs::Valmax<T>()), bs::Valmax<r_t>());
  STF_EQUAL(successor(bs::Zero<T>()), bs::One<r_t>());
} // end of test for signed_int_


