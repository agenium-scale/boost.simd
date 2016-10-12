//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitinteger.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/bitincrement.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" bit integerreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::bitinteger;
  using r_t = decltype(bitinteger(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bitinteger(bs::Nan<T>()), -bs::Valmax<r_t>());
#endif
#if !defined(BOOST_SIMD_NO_DENORMALS)
  STF_EQUAL(bitinteger(bs::Bitincrement<T>()), bs::One<r_t>());
  STF_EQUAL(bitinteger(-bs::Bitincrement<T>()), bs::Mone<r_t>());
#endif
  STF_EQUAL(bitinteger(bs::Zero<T>()), bs::Zero<r_t>());
}
