//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/ifnotsub.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>
//TODO LOGICAL
STF_CASE_TPL (" ifnotsub real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnotsub;
  using bs::logical;
  using r_t = decltype(ifnotsub(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
//   STF_EQUAL(ifnotsub(logical<T>(T(0)),T(1),T(2)), T(-1));
//   STF_EQUAL(ifnotsub(bs::True<logical<T> >(),T(1),T(2)), T(1));
//   STF_IEEE_EQUAL(ifnotsub(bs::False<logical<T> >(),bs::Inf<T>(),bs::Inf<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(ifnotsub(bs::False<logical<T> >(),bs::Minf<T>(),bs::Minf<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(ifnotsub(bs::False<logical<T> >(),bs::Nan<T>(),bs::Nan<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(ifnotsub(bs::False<logical<T> >(),bs::Zero<T>(),bs::One<T>()), bs::Mone<r_t>());
  STF_EQUAL(ifnotsub(T(0),T(1),T(2)), T(-1));
  STF_EQUAL(ifnotsub(T(1),T(1),T(2)), T(1));
  STF_IEEE_EQUAL(ifnotsub(T(1),bs::Inf<T>(),bs::Inf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(ifnotsub(T(0),bs::Minf<T>(),bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(ifnotsub(T(0),bs::Nan<T>(),bs::Nan<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(ifnotsub(T(0),bs::Zero<T>(),bs::One<T>()), bs::Mone<r_t>());
} // end of test for floating_

STF_CASE_TPL (" ifnotsub integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnotsub;
  using bs::logical;
  using r_t = decltype(ifnotsub(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(ifnotsub(logical<T>(T(-1)),T(1),T(2)), T(1));
  STF_EQUAL(ifnotsub(logical<T>(T(0)),T(2),T(1)), T(1));
  STF_EQUAL(ifnotsub(logical<T>(bs::Zero<T>()),bs::Zero<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(ifnotsub(T(-1),T(1),T(2)), T(1));
  STF_EQUAL(ifnotsub(T(0),T(2),T(1)), T(1));
  STF_EQUAL(ifnotsub(bs::Zero<T>(),bs::Zero<T>(),bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_

