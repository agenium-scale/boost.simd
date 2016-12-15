//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/std.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/detail/constant/limitexponent.hpp>
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/function/scalar/dec.hpp>


STF_CASE_TPL("ldexp std", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ldexp;

  using iT = bd::as_integer_t<T>;
  using r_t = decltype(ldexp(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::std_(ldexp)(bs::Inf<T>(),  2), bs::Inf<r_t>());
  STF_EQUAL(bs::std_(ldexp)(bs::Minf<T>(), 2), bs::Minf<r_t>());
  STF_IEEE_EQUAL(bs::std_(ldexp)(bs::Nan<T>(),  2), bs::Nan<r_t>());
#endif
  STF_EQUAL(bs::std_(ldexp)(bs::Mone<T>(), 2), -bs::Four<r_t>());
  STF_EQUAL(bs::std_(ldexp)(bs::One<T>(),  2), bs::Four<r_t>());
  STF_EQUAL(bs::std_(ldexp)(bs::Zero<T>(), 2), bs::Zero<r_t>());
  STF_EQUAL(bs::std_(ldexp)(bs::One <T>(), bs::Minexponent<T>()), bs::Smallestposval<r_t>());
  STF_EQUAL(bs::std_(ldexp)(bs::One<T>()-bs::Halfeps<T>(),  bs::Maxexponent<T>()), bs::Valmax<T>()/2);
  STF_EQUAL(bs::std_(ldexp)(bs::One<T>()-bs::Halfeps<T>(),  bs::Limitexponent<T>()), bs::Valmax<T>());
#ifndef BOOST_SIMD_NO_DENORMALS
  using bs::dec;
  STF_EQUAL(bs::std_(ldexp)(bs::One <T>(), dec(bs::Minexponent<T>())), bs::Smallestposval<T>()/2);
  STF_EQUAL(bs::std_(ldexp)(bs::Two <T>(), dec(bs::Minexponent<T>())), bs::Smallestposval<T>());
  STF_EQUAL(bs::std_(ldexp)(bs::Two <T>(), dec(bs::Minexponent<T>()-1)), bs::Smallestposval<T>()/2);
  STF_EQUAL(bs::std_(ldexp)(bs::One <T>(), bs::Minexponent<T>()-5), bs::Smallestposval<T>()/32);
#endif
}
