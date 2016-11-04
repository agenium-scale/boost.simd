//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/eps.hpp>
#include <scalar_test.hpp>

#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/eps.hpp>

STF_CASE_TPL ("eps for IEEE types",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::eps;
  using r_t = decltype(eps(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
 #ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(eps(bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(eps(bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(eps(bs::Nan<T>()), bs::Nan<r_t>());
 #endif

  STF_EQUAL(eps(T{-1}), bs::Eps<r_t>());
  STF_EQUAL(eps(T{1}) , bs::Eps<r_t>());

 #if !defined(BOOST_SIMD_NO_DENORMALS)
  STF_EQUAL(eps(T{0}), bs::Mindenormal<r_t>());
 #endif
}

STF_CASE_TPL ("eps on integers",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::eps;
  using r_t = decltype(eps(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(eps(T(-1)), T{1});
  STF_EQUAL(eps(T(0)) , T{1});
  STF_EQUAL(eps(T(-1)), T{1});
  STF_EQUAL(eps(T(42)), T{1});
}
