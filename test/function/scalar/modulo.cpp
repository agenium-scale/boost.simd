//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/modulo.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" modulo integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::modulo;

  using r_t = decltype(modulo(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
  STF_EQUAL(modulo(bs::One<T>(), bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(modulo(bs::One<T>(),bs::Two<T>()), bs::One<r_t>());
  STF_EQUAL(modulo(bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
} // end of test for integer_


