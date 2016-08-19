//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_else.hpp>
#include <scalar_test.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" if_else integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_else;
  using bs::logical;
  using r_t = decltype(if_else(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(if_else( bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(if_else( bs::One<T>(), bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
  STF_EQUAL(if_else( bs::Zero<T>(), bs::One<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_

STF_CASE_TPL (" if_else real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::if_else;

  using bs::logical;
  using r_t = decltype(if_else(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(if_else( bs::One<T>(), bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(if_else( bs::One<T>(),bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
  STF_EQUAL(if_else( bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_









