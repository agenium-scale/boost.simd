//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/fast.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL(" rec",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rec;

  // return type conformity test
  STF_EXPR_IS( rec(T()) , T );

  // specific values tests
  STF_IEEE_EQUAL(rec(bs::Inf<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(rec(bs::Minf<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(rec(bs::Mone<T>()), bs::Mone<T>());
  STF_IEEE_EQUAL(rec(bs::Mzero<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(rec(bs::Nan<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(rec(bs::One<T>()), bs::One<T>());
  STF_IEEE_EQUAL(rec(bs::Zero<T>()), bs::Inf<T>());
} // end of test for floating_

STF_CASE_TPL(" rec",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rec;
  using bs::fast_;

  // return type conformity test
  STF_EXPR_IS( bs::fast_(rec)(T()) , T );
  //For scalar is it a call redibs::fast_(rec)ted to bs::fast_(rec)
  // specific values tests
  STF_IEEE_EQUAL(bs::fast_(rec)(bs::Inf<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(bs::fast_(rec)(bs::Minf<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(bs::fast_(rec)(bs::Mone<T>()), bs::Mone<T>());
  STF_IEEE_EQUAL(bs::fast_(rec)(bs::Mzero<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(bs::fast_(rec)(bs::Nan<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(bs::fast_(rec)(bs::One<T>()), bs::One<T>());
  STF_IEEE_EQUAL(bs::fast_(rec)(bs::Zero<T>()), bs::Inf<T>());
} // end of test for floating_
