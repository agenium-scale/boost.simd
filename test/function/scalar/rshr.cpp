//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rshr.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" rshrinteger",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::rshr;

  using r_t = decltype(rshr(T(),int()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);
  std::cout << std::endl;

  // specific values tests
  STF_EQUAL(rshr(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(rshr(bs::One<T>(), -1), bs::Two<r_t>());
  STF_EQUAL(rshr(bs::One<T>(), 1), bs::Zero<r_t>());
} // end of test for integer_
