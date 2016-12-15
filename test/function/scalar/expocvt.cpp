//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/expocvt.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>

STF_CASE_TPL (" expocvt real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using iT = bd::as_integer_t<T>;
  using bs::expocvt;
  using r_t = decltype(expocvt(T()));


  // return type conformity test
  STF_TYPE_IS(r_t, T); //(bd::as_integer_t<T, signed>));

  // specific values tests

  for( iT i=-bs::Maxexponent<T>(); i < bs::Maxexponent<T>(); ++i)
  {
    std::cout << i << std::endl;
    STF_EQUAL(expocvt(T(i)),std::ldexp(T(1), i));
  }
} // end of test for floating_

