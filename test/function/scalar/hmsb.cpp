//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/hmsb.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/function/shr.hpp>
// TODO LOGICAL

STF_CASE_TPL (" hmsb real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::hmsb;

  // specific values tests
  STF_EQUAL(hmsb(bs::Allbits<T>()), 1u);
  STF_EQUAL(hmsb(bs::Inf<T>()), 0u);
  STF_EQUAL(hmsb(bs::Minf<T>()), 1u);
  STF_EQUAL(hmsb(bs::Mone<T>()), 1u);
  STF_EQUAL(hmsb(bs::Nan<T>()), 1u);
  STF_EQUAL(hmsb(bs::One<T>()), 0u);
  STF_EQUAL(hmsb(bs::Signmask<T>()), 1u);
  STF_EQUAL(hmsb(bs::Zero<T>()), 0u);
} // end of test for real_

// STF_CASE_TPL (" hmsb signed_int",  STF_SIGNED_INTEGRAL_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::hmsb;

//   using r_t = decltype(hmsb(T()));

//   // specific values tests
//   STF_EQUAL(hmsb(bs::Allbits<T>()), r_t((1ull << 1) - 1));
//   STF_EQUAL(hmsb(bs::One<T>()), bs::Zero<r_t>());
//   STF_EQUAL(hmsb(bs::Signmask<T>()), r_t((1ull << 1) - 1));
//   STF_EQUAL(hmsb(bs::Zero<T>()), bs::Zero<r_t>());
// } // end of test for signed_int_

// STF_CASE_TPL (" hmsb unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::hmsb;

//   using r_t = decltype(hmsb(T()));

//   // specific values tests
//   STF_EQUAL(hmsb(bs::Allbits<T>()), r_t((1ull << 1) - 1));
//   STF_EQUAL(hmsb(bs::One<T>()), bs::Zero<r_t>());
//   STF_EQUAL(hmsb(bs::Zero<T>()), bs::Zero<r_t>());
// } // end of test for unsigned_int_

// STF_CASE_TPL (" hmsb logical", STF_NUMERIC_TYPES)
// {
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
//   using bs::hmsb;
//
//   using bs::native;
//   using bs::logical;
//   using bs::meta::cardinal_of;
//   typedef STF_DEFAULT_EXTENSION  ext_t;
//   typedef native<logical<T>,ext_t>                          T;
//   using r_t = decltype(hmsb(T));

//   // specific values tests
//   STF_EQUAL(hmsb(bs::True<T>())  , r_t((1ull << 1) - 1));
//   STF_EQUAL(hmsb(bs::False<T>()) , bs::Zero<r_t>());
// }
