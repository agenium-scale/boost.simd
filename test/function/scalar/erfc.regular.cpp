//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/erfc.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/function/is_less.hpp>

STF_CASE_TPL (" erfc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::erfc;
  using r_t = decltype(erfc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(erfc(bs::Inf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(erfc(bs::Minf<T>()), bs::Two<r_t>());
  STF_IEEE_EQUAL(erfc(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_ULP_EQUAL(erfc(bs::Mzero<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(erfc(T(0.1)), T(0.887537083981715107796724928256), 0.5);
  STF_ULP_EQUAL(erfc(T(0.4)), T(0.57160764495333154489639615468), 0.5);
  STF_ULP_EQUAL(erfc(bs::Half<T>()), T(0.479500122186953462317253346108), 1.5);
  STF_ULP_EQUAL(erfc(bs::One<T>()), T(0.157299207050285130658779364917), 0.5);
  STF_ULP_EQUAL(erfc(bs::Two<T>()), T(0.00467773498104726583793074363275), 1);
  STF_ULP_EQUAL(erfc(bs::Zero<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(erfc(T(6)), T(0.0000000000000000215197367124989131165933503992), 0.5);
  STF_EXPECT(bs::is_less(erfc((bs::Ten<T>()- T(2.088487583762545e-45))), bs::Eps<T>()));
  STF_EXPECT(bs::is_less(erfc(T(15))- T(7.212994172451206e-100), bs::Eps<T>()));

  STF_ULP_EQUAL(erfc(-T(0.1)),        bs::std_(erfc)(-T(0.1)),        0.5);
  STF_ULP_EQUAL(erfc(-T(0.4)),        bs::std_(erfc)(-T(0.4)),        0.5);
  STF_ULP_EQUAL(bs::std_(erfc)(-bs::Half<T>()), (erfc)(-bs::Half<T>()), 0.5);
  STF_ULP_EQUAL(erfc(-bs::One<T>()),  bs::std_(erfc)(-bs::One<T>()),  0.5);
  STF_ULP_EQUAL(erfc(-bs::Two<T>()),  bs::std_(erfc)(-bs::Two<T>()),  1);
  STF_ULP_EQUAL(erfc(T(-6)), T(2), 0.5);
}




