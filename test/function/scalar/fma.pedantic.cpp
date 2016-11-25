//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/inc.hpp>
#include <cmath>

STF_CASE_TPL (" bs::pedantic_(fma) real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::fma;

  // return type conformity test
  STF_EXPR_IS(bs::pedantic_(fma)(T(),T(),T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::pedantic_(fma)(bs::Inf<T>(), bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(bs::pedantic_(fma)(bs::Minf<T>(), bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(bs::pedantic_(fma)(bs::Nan<T>(), bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(bs::pedantic_(fma)(bs::Mone<T>(), bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(bs::pedantic_(fma)(bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::pedantic_(fma)(bs::One<T>()+bs::Eps<T>(), bs::One<T>()-bs::Eps<T>(),bs::Mone<T>()), -bs::Eps<T>()*bs::Eps<T>());
  STF_EQUAL(bs::pedantic_(fma)(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
#ifndef  STF_DONT_CARE__FMA_OVERFLOW
  STF_EQUAL(bs::pedantic_(fma)(bs::Valmax<T>(), bs::Two<T>(), -bs::Valmax<T>()), bs::Valmax<T>());
#endif
} // end of test for floating_

STF_CASE_TPL (" bs::pedantic_(fma) signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::fma;

  // return type conformity test

  STF_EXPR_IS(bs::pedantic_(fma)(T(),T(),T()), T);

  // specific values tests
  STF_EQUAL(bs::pedantic_(fma)(bs::Mone<T>(), bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(bs::pedantic_(fma)(bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::pedantic_(fma)(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(bs::pedantic_(fma)(bs::Valmax<T>(), bs::Two<T>(), bs::inc(bs::Valmin<T>())), bs::Valmax<T>());
} // end of test for signed_int_

STF_CASE_TPL (" bs::pedantic_(fma) unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::fma;

  // return type conformity test
  STF_EXPR_IS(bs::pedantic_(fma)(T(),T(),T()), T);

  // specific values tests
  STF_EQUAL(bs::pedantic_(fma)(bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(bs::pedantic_(fma)(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" bs::pedantic_(fma) std real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::fma;

  // return type conformity test
  STF_EXPR_IS(bs::std_(fma)(T(),T(),T()), T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL( bs::std_(fma)(bs::Inf<T>(), bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL( bs::std_(fma)(bs::Minf<T>(), bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL( bs::std_(fma)(bs::Nan<T>(), bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL( bs::std_(fma)(bs::Mone<T>(), bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL( bs::std_(fma)(bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL( bs::std_(fma)(bs::One<T>()+bs::Eps<T>(), bs::One<T>()-bs::Eps<T>(),bs::Mone<T>()), -bs::Eps<T>()*bs::Eps<T>());
  STF_EQUAL( bs::std_(fma)(bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL( bs::std_(fma)(bs::Valmax<T>(), bs::Two<T>(), -bs::Valmax<T>()), bs::Valmax<T>());
} // end of test for floating_
