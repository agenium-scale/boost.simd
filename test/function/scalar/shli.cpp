//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/shli.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" shli_integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::shli;
  using bs::tag::shli_;
  using iT =  boost::dispatch::as_integer_t<T>;
  using r_t = decltype(shli(T(),iT()));
  typedef T wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(shli(bs::One<T>(),bs::One<iT>()), bs::Two<r_t>());
  STF_EQUAL(shli(bs::One<T>(),bs::Zero<iT>()), bs::One<r_t>());
  STF_EQUAL(shli(bs::Zero<T>(),bs::One<iT>()), bs::Zero<r_t>());
} // end of test for integer_

STF_CASE_TPL (" shli_real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::shli;
  using bs::tag::shli_;
  using iT =  boost::dispatch::as_integer_t<T>;
  using r_t = decltype(shli(T(),iT()));
  typedef T wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(shli(bs::One<T>(),bs::Zero<iT>()), bs::One<r_t>());
  STF_EQUAL(shli(bs::Zero<T>(),bs::One<iT>()), bs::Zero<r_t>());
} // end of test for floating_
