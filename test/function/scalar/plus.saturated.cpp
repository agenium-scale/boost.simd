//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/plus.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/two.hpp>

//saturated_TODO
STF_CASE_TPL (" plus signed int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::plus;
  using r_t = decltype(bs::saturated_(plus)(T(),T()));
  typedef T wished_r_t;


  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(bs::saturated_(plus)(bs::Mone<T>(), bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::Valmin<T>(),bs::Mone<T>()), bs::Valmin<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL (" plus unsigned int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::plus;
  using r_t = decltype(bs::saturated_(plus)(T(),T()));
  typedef T wished_r_t;
  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(bs::saturated_(plus)(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" plus real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::plus;
  using r_t = decltype(bs::saturated_(plus)(T(),T()));
  typedef T wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::saturated_(plus)(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(bs::saturated_(plus)(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(bs::saturated_(plus)(bs::Mone<T>(), bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::saturated_(plus)(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for floating_
