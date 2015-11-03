//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/exp2.hpp>
#include <stf.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/is_flint.hpp>

STF_CASE_TPL ( "exp2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::exp2;
  using r_t = decltype(exp2(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(exp2(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(exp2(bs::Mone<T>()), bs::Half<r_t>(), 0.75);
  STF_ULP_EQUAL(exp2(bs::One<T>()), bs::Two<r_t>(), 0.75);
  STF_ULP_EQUAL(exp2(bs::Zero<T>()), bs::One<r_t>(), 0.75);

 for(int i=0; i < 100 ; i++)
 {
   STF_TEST(bs::is_flint(exp2(T(i))));
 }
}


