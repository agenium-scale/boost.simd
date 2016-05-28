//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/shri.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/three.hpp>

STF_CASE_TPL (" shri uit",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::shri;
  using iT = bd::as_integer_t<T, unsigned>;
  using r_t = decltype(shri(T(), iT()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(shri(T(2),1), bs::One<T>());
  STF_EQUAL(shri(bs::Valmax<T>(),(sizeof(T)*8-1)), bs::One<r_t>());
  STF_EQUAL(shri(bs::Valmax<T>(),(sizeof(T)*8-2)), bs::Three<r_t>());
  STF_EQUAL(shri(bs::One<T>(),1), bs::Zero<r_t>());
  STF_EQUAL(shri(bs::Zero<T>(),1), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" shri si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::shri;
  using iT = bd::as_integer_t<T, unsigned>;
  using r_t = decltype(shri(T(), iT()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(shri(T(2),1), bs::One<T>());
  STF_EQUAL(shri(bs::Mone<T>(),(sizeof(T)*8-1)), bs::One<r_t>());
  STF_EQUAL(shri(bs::Mone<T>(),(sizeof(T)*8-2)), bs::Three<r_t>());
  STF_EQUAL(shri(bs::One<T>(),1), bs::Zero<r_t>());
  STF_EQUAL(shri(bs::Zero<T>(),1), bs::Zero<r_t>());
} // end of test for unsigned_int_
