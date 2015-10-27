//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/adds.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
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


STF_CASE_TPL (" adds signed int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::adds;
  using r_t = decltype(adds(T(),T()));
  typedef T wished_r_t;


  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(adds(bs::Mone<T>(), bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(adds(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(adds(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(adds(bs::Valmin<T>(),bs::Mone<T>()), bs::Valmin<T>());
  STF_EQUAL(adds(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

STF_CASE_TPL (" adds unsigned int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::adds;
  using r_t = decltype(adds(T(),T()));
  typedef T wished_r_t;
  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(adds(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(adds(bs::Valmax<T>(),bs::One<T>()), bs::Valmax<T>());
  STF_EQUAL(adds(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" adds real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::adds;
  using r_t = decltype(adds(T(),T()));
  typedef T wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(adds(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(adds(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(adds(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(adds(bs::Mone<T>(), bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(adds(bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(adds(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for floating_
