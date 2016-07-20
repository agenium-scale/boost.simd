//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/modulus.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


STF_CASE_TPL( "Check modulus behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::modulus;
  using r_t = decltype(modulus(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(modulus(bs::Inf<T>()),  bs::Inf<r_t>());
  STF_EQUAL(modulus(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(modulus(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_EQUAL(modulus(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(modulus(bs::One<T>()),  bs::One<r_t>());
  STF_EQUAL(modulus(bs::Mone<T>()), bs::One<r_t>());

}




