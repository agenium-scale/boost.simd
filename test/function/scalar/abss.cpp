//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/abss.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>


STF_CASE_TPL( "Check abss behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::abss;
  using r_t = decltype(abss(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(abss(bs::Inf<T>()),  bs::Inf<r_t>());
  STF_IEEE_EQUAL(abss(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(abss(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(abss(bs::Mone<T>()), bs::One<T>());
  STF_IEEE_EQUAL(abss(bs::One<T>()), bs::One<T>());
  STF_IEEE_EQUAL(abss(bs::Valmax<T>()), bs::Valmax<T>());
  STF_IEEE_EQUAL(abss(bs::Valmin<T>()), bs::Valmax<T>());
  STF_IEEE_EQUAL(abss(bs::Zero<T>()), bs::Zero<T>());
}



