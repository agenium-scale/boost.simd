//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/dot.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" dot",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::dot;

  // specific values tests
  STF_EQUAL(dot(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(dot(bs::Minf<T>(), bs::Minf<T>()), bs::Inf<T>());
  STF_EQUAL(dot(bs::Mone<T>(), bs::Mone<T>()), bs::One<T>());
  STF_IEEE_EQUAL(dot(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
  STF_EQUAL(dot(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(dot(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
} // end of test for floating_


