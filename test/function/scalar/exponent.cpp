//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/exponent.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" exponent real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::exponent;
  using r_t = decltype(exponent(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(exponent(bs::Minf<T>()), bs::Zero<r_t>());
  STF_EQUAL(exponent(bs::Inf <T>()), bs::Zero<r_t>());
  STF_EQUAL(exponent(bs::Nan <T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(exponent(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(exponent(bs::One<T>()),  bs::Zero<r_t>());
  STF_EQUAL(exponent(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(exponent(bs::Two<T>()),  bs::One<r_t>() );
  STF_EQUAL(exponent(T(1.5)),        bs::Zero<r_t>() );
}
STF_CASE_TPL (" exponent i",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::exponent;
  using r_t = decltype(exponent(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, signed>));

  // specific values tests
  STF_EQUAL(exponent(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(exponent(bs::One<T>()),  bs::Zero<r_t>());
  STF_EQUAL(exponent(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(exponent(bs::Two<T>()),  bs::Zero<r_t>() );

}


