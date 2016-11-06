//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/dec.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mtwo.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" dec signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::dec;

  // return type conformity test
  STF_EXPR_IS(dec(T()), T);

  // specific values tests
  STF_EQUAL(dec(bs::Mone<T>()), bs::Mtwo<T>());
  STF_EQUAL(dec(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(dec(bs::Zero<T>()), bs::Mone<T>());
}

STF_CASE_TPL (" decunsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::dec;

  // return type conformity test
  STF_EXPR_IS(dec(T()), T);

  // specific values tests
  STF_EQUAL(dec(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(dec(bs::Two<T>()), bs::One<T>());
  STF_EQUAL(dec(bs::Zero<T>()), bs::Valmax<T>());
}

STF_CASE_TPL(" dec floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::dec;

  // return type conformity test
  STF_EXPR_IS(dec(T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(dec(bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(dec(bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(dec(bs::Minf<T>()), bs::Minf<T>());
#endif
  STF_EQUAL(dec(bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(dec(bs::Two<T>()), bs::One<T>());
  STF_EQUAL(dec(bs::Zero<T>()), bs::Mone<T>());
}
