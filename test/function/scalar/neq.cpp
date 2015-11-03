//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/neq.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>
#include <nontrivial.hpp>

STF_CASE_TPL (" neq integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::neq;
  using r_t = decltype(neq(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(neq(bs::One<T>(), bs::One<T>()), r_t(false));
  STF_EQUAL(neq(bs::One<T>(),bs::Zero<T>()), r_t(true));
  STF_EQUAL(neq(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
} // end of test for integer_

STF_CASE_TPL (" neq real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::neq;
  using r_t = decltype(neq(T(), T()));

  // return type conformity test
 STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(neq(bs::Inf<T>(), bs::Inf<T>()), r_t(false));
  STF_EQUAL(neq(bs::Minf<T>(), bs::Minf<T>()), r_t(false));
  STF_EQUAL(neq(bs::Nan<T>(), bs::Nan<T>()), r_t(true));
  STF_EQUAL(neq(bs::One<T>(),bs::Zero<T>()), r_t(true));
  STF_EQUAL(neq(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
} // end of test for floating_

STF_CASE ( "neq bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::neq;

  using r_t = decltype(neq(bool(), bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);


  // specific values tests
  STF_EQUAL(neq(true, false), true);
  STF_EQUAL(neq(false, true), true);
  STF_EQUAL(neq(true, true), false);
  STF_EQUAL(neq(false, false), false);
}


namespace foo
{
  template <class T>
  nontrivial<T> operator !=(const nontrivial<T> & z1, const nontrivial<T> z2)
  {
    return perform(z1, z2);
  }
}

STF_CASE_TPL( "Check neq behavior with exotic type", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::neq;
  using foo::nontrivial;
  using r_t = decltype(neq(nontrivial<T>(), nontrivial<T>()));
  STF_TYPE_IS(r_t, nontrivial<T>);

  STF_EQUAL(neq(nontrivial<T>(1, 2), nontrivial<T>(3, 4)), nontrivial<T>(4, 8));
}
