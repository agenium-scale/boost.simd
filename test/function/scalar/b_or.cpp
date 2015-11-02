//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/b_or.hpp>
#include <simd_test.hpp>
#include <nontrivial.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" bitwise xor_real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::b_or;
  using r_t = decltype(b_or(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(b_or(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_or(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_or(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(b_or(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(b_or(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" bitwise xor_integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::b_or;
  using r_t = decltype(b_or(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(b_or(bs::One<T>(), bs::One<T>()), bs::Zero<r_t>());
  STF_EQUAL(b_or(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
  STF_EQUAL(b_or(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_


STF_CASE_TPL("bitwise xor_mix", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::b_or;
  using siT = bd::as_integer_t<T>;
  using uiT = bd::as_integer_t<T, unsigned>;

  // return type conformity test
  STF_EXPR_IS(b_or(T(),uiT()), T);
  STF_EXPR_IS(b_or(T(),siT()), T);
  STF_EXPR_IS(b_or(uiT(), T()), uiT);
  STF_EXPR_IS(b_or(siT(), T()), siT);

  // specific values tests
  STF_EQUAL(b_or(bs::Nan<T>(),bs::Valmax<uiT>()), bs::Zero<T>());
  STF_EQUAL(b_or(bs::Nan<T>(), bs::Mone<siT>()), bs::Zero<T>());
  STF_EQUAL(b_or(bs::Mone<siT>(),bs::Zero<T>()), bs::Mone<siT>());
  STF_EQUAL(b_or(bs::Valmax<uiT>(), bs::Zero<T>()), bs::Valmax<uiT>());
}

namespace foo
{
  template <class T>
  nontrivial<T> operator ^(const nontrivial<T> & z1, const nontrivial<T> z2)
  {
    return perform(z1, z2);
  }
}

STF_CASE_TPL( "Check b_or behavior with exotic type", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::b_or;
  using foo::nontrivial;
  using r_t = decltype(b_or(nontrivial<T>(), nontrivial<T>()));
  STF_TYPE_IS(r_t, nontrivial<T>);

  STF_EQUAL(b_or(nontrivial<T>(1, 2), nontrivial<T>(3, 4)), nontrivial<T>(4, 8));
}
