//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/is_simd_logical.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>

STF_CASE_TPL (" is_simd_logical real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_simd_logical;
  using r_t = decltype(is_simd_logical(T()));

  // specific values tests
  STF_EQUAL(is_simd_logical(-bs::Nan<T>()), r_t(false));
  STF_EQUAL(is_simd_logical(bs::Inf<T>()), r_t(false));
  STF_EQUAL(is_simd_logical(bs::Minf<T>()), r_t(false));
  STF_EQUAL(is_simd_logical(bs::Mone<T>()), r_t(false));
  STF_EQUAL(is_simd_logical(bs::Nan<T>()), r_t(true));
  STF_EQUAL(is_simd_logical(bs::One<T>()), r_t(false));
  STF_EQUAL(is_simd_logical(bs::Zero<T>()), r_t(true));
} // end of test for floating_

STF_CASE_TPL (" is_simd_logical integer",   STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_simd_logical;
  using r_t = decltype(is_simd_logical(T()));

  // specific values tests
  STF_EQUAL(is_simd_logical(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_simd_logical(bs::One<T>()), r_t(false));
  STF_EQUAL(is_simd_logical(bs::Zero<T>()), r_t(true));
} // end of test for floating_

STF_CASE_TPL (" is_simd_logical integer",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_simd_logical;
  using r_t = decltype(is_simd_logical(T()));

  // specific values tests
  STF_EQUAL(is_simd_logical(bs::Valmax<T>()), r_t(true));
  STF_EQUAL(is_simd_logical(bs::One<T>()), r_t(false));
  STF_EQUAL(is_simd_logical(bs::Zero<T>()), r_t(true));
} // end of test for floating_
