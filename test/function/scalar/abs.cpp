//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

#include <boost/simd/function/std.hpp>
#include <boost/simd/function/saturated.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check abs behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::abs;
  using r_t = decltype(abs(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(abs(bs::Inf<T>()),  bs::Inf<r_t>());
  STF_EQUAL(abs(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(abs(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(abs(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(abs(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(abs(bs::Mone<T>()), bs::One<r_t>());
}

STF_CASE_TPL( "Check abs behavior with signed integral", STF_SIGNED_INTEGRAL_TYPES )
{
  namespace bs = boost::simd;
  using bs::abs;
  using r_t = decltype(abs(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(abs(bs::Inf<T>()),  bs::Inf<r_t>());
  STF_EQUAL(abs(bs::Minf<T>()), bs::Minf<r_t>());
  STF_EQUAL(abs(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(abs(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(abs(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(abs(bs::Mone<T>()), bs::One<r_t>());
}

STF_CASE_TPL( "Check std abs behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::abs;
  using r_t = decltype(abs(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::std_(abs)(bs::Inf<T>()),  bs::Inf<r_t>());
  STF_EQUAL(bs::std_(abs)(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(bs::std_(abs)(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(bs::std_(abs)(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bs::std_(abs)(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(bs::std_(abs)(bs::Mone<T>()), bs::One<r_t>());
}

STF_CASE_TPL( "Check std abs behavior with signed integral", STF_SIGNED_INTEGRAL_TYPES )
{
  namespace bs = boost::simd;
  using bs::abs;
  using r_t = decltype(abs(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::std_(abs)(bs::Inf<T>()),  bs::Inf<r_t>());
  STF_EQUAL(bs::std_(abs)(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(bs::std_(abs)(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bs::std_(abs)(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(bs::std_(abs)(bs::Mone<T>()), bs::One<r_t>());
}

STF_CASE_TPL( "Check saturated abs behavior ", STF_SIGNED_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::abs;
  using r_t = decltype(bs::saturated_(abs)(T()));
  STF_TYPE_IS(r_t, T);

  STF_EQUAL(bs::saturated_(abs)(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(bs::saturated_(abs)(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(bs::saturated_(abs)(bs::Mone<T>()), bs::One<r_t>());
}
