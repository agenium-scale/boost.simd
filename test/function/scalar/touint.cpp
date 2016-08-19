//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/touint.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


STF_CASE_TPL (" touint real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::touint;
  using r_t = decltype(touint(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
  STF_EQUAL(touint(bs::One<T>()) , bs::One<r_t>());
  STF_EQUAL(touint(bs::Zero<T>()), bs::Zero<r_t>());
 } // end of test for floating_
