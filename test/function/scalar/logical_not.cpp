//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/logical_not.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>
#include <nontrivial.hpp>

STF_CASE_TPL (" logical_not integer",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::logical_not;
  using bs::logical;


  using r_t = decltype(logical_not(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,logical<T>);

  // specific values tests
  STF_EQUAL(logical_not(T(1)), r_t(false));
  STF_EQUAL(logical_not(T(0)), r_t(true));
} // end of test for integer_


namespace foo
{
  template <class T>
  nontrivial<T> operator !(const nontrivial<T> & z1)
  {
    return perform(z1);
  }
}

STF_CASE_TPL( "Check logical_not behavior with exotic type", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::logical_not;
  using foo::nontrivial;
  using r_t = decltype(logical_not(nontrivial<T>()));
  STF_TYPE_IS(r_t, nontrivial<T>);

  STF_EQUAL(logical_not(nontrivial<T>(1, 2)), nontrivial<T>(2, 6));
}
