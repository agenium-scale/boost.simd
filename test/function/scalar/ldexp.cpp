//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/fast.hpp>
#include <simd_test.hpp>
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
#include <boost/simd/constant/maxexponent.hpp>
#include <boost/simd/constant/limitexponent.hpp>
#include <boost/simd/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/function/scalar/dec.hpp>

STF_CASE_TPL("ldexp", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ldexp;

  using iT = bd::as_integer_t<T>;
  using r_t = decltype(ldexp(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ldexp(bs::Inf<T>(),  2), bs::Inf<r_t>());
  STF_EQUAL(ldexp(bs::Minf<T>(), 2), bs::Minf<r_t>());
  STF_IEEE_EQUAL(ldexp(bs::Nan<T>(),  2), bs::Nan<r_t>());
#endif

  STF_EQUAL(ldexp(bs::Mone<T>(), 2), -bs::Four<r_t>());
  STF_EQUAL(ldexp(bs::One<T>(),  2), bs::Four<r_t>());
  STF_EQUAL(ldexp(bs::Zero<T>(), 2), bs::Zero<r_t>());
  STF_EQUAL(ldexp(bs::One <T>(), bs::Minexponent<T>()), bs::Smallestposval<r_t>());
  STF_EQUAL(ldexp(bs::One<T>()-bs::Halfeps<T>(),  bs::Maxexponent<T>()), bs::Valmax<T>()/2);
  STF_EQUAL(ldexp(bs::One<T>()-bs::Halfeps<T>(),  bs::Limitexponent<T>()), bs::Valmax<T>());

#ifndef BOOST_SIMD_NO_DENORMALS
  using bs::dec;
  STF_EQUAL(ldexp(bs::One <T>(), dec(bs::Minexponent<T>())), bs::Smallestposval<T>()/2);
  STF_EQUAL(ldexp(bs::Two <T>(), dec(bs::Minexponent<T>())), bs::Smallestposval<T>());
  STF_EQUAL(ldexp(bs::Two <T>(), dec(bs::Minexponent<T>()-1)), bs::Smallestposval<T>()/2);
  STF_EQUAL(ldexp(bs::One <T>(), bs::Minexponent<T>()-5), bs::Smallestposval<T>()/32);
#endif
}

STF_CASE_TPL("ldexp", STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ldexp;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(ldexp(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(ldexp(bs::One <T>(), 2), r_t(4));
  STF_EQUAL(ldexp(bs::Three<T>(), 2), r_t(12));
  STF_EQUAL(ldexp(bs::Mone<T>(), 2), r_t(-4));
}

STF_CASE_TPL("ldexp fast", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ldexp;

  using bs::fast_;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(bs::fast_(ldexp)(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::fast_(ldexp)(bs::Inf<T>(),  2), bs::Inf<r_t>());
  STF_EQUAL(bs::fast_(ldexp)(bs::Minf<T>(), 2), bs::Minf<r_t>());
  STF_IEEE_EQUAL(bs::fast_(ldexp)(bs::Nan<T>(),  2), bs::Nan<r_t>());
#endif
  STF_EQUAL(bs::fast_(ldexp)(bs::Mone<T>(), 2), -bs::Four<r_t>());
  STF_EQUAL(bs::fast_(ldexp)(bs::One<T>(),  2), bs::Four<r_t>());
  STF_EQUAL(bs::fast_(ldexp)(bs::Zero<T>(), 2), bs::Zero<r_t>());
  STF_EQUAL(bs::fast_(ldexp)(bs::One <T>(), bs::Minexponent<T>()), bs::Smallestposval<r_t>());
  STF_EQUAL(bs::fast_(ldexp)(bs::One<T>()-bs::Halfeps<T>(),  bs::Maxexponent<T>()), bs::Valmax<T>()/2);
}

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
