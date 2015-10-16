//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//#include <boost/simd/function/eps.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/eps.hpp>
//TODO

// STF_CASE_TPL (" eps real",  STF_IEEE_TYPES)
// {
//   namespace bs = boost::simd;
//   using bs::eps;
//   using r_t = decltype(eps(T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
// #ifndef STF_NO_INVALIDS
//   STF_IEEE_EQUAL(eps(bs::Inf<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(eps(bs::Minf<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(eps(bs::Nan<T>()), bs::Nan<r_t>());
// #endif
//   STF_EQUAL(eps(bs::Mone<T>()), bs::Eps<r_t>());
//   STF_EQUAL(eps(bs::One<T>()), bs::Eps<r_t>());
// #if !defined(STF_NO_DENORMALS)
//   STF_EQUAL(eps(bs::Zero<T>()), bs::Mindenormal<r_t>());
// #endif

// }

// STF_CASE_TPL (" eps unsigned_int",  STF_UNSIGNED_ALL_INTEGRAL_TYPES)
// {
//   namespace bs = boost::simd;
//   using bs::eps;
//   using r_t = decltype(eps(T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
//   STF_EQUAL(eps(bs::One<T>()), bs::One<r_t>());
//   STF_EQUAL(eps(bs::Zero<T>()), bs::One<r_t>());
// }

// STF_CASE_TPL (" eps signed_int",  STF_SIGNED_ALL_INTEGRAL_SIGNED_TYPES)
// {
//   namespace bs = boost::simd;
//   using bs::eps;
//   using r_t = decltype(eps(T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
//   STF_EQUAL(eps(bs::Mone<T>()), bs::One<r_t>());
//   STF_EQUAL(eps(bs::One<T>()), bs::One<r_t>());
//   STF_EQUAL(eps(bs::Zero<T>()), bs::One<r_t>());
//   STF_EQUAL(eps(bs::Two<T>()), bs::One<r_t>());
// }
