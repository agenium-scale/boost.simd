//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/erf.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/five.hpp>
#include <boost/simd/function/rsqrt.hpp>

STF_CASE_TPL (" erf",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::erf;
  using r_t = decltype(erf(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(erf(bs::Minf<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(erf(bs::Inf<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(erf(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(erf(bs::Mzero<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(erf(T(0.1)), T(0.112462916018284892203275071744), 0);
  STF_ULP_EQUAL(erf(bs::Half<T>()), T(0.520499877813046537682746653892), 0.5);
  STF_ULP_EQUAL(erf(bs::One<T>()), T(0.842700792949714869341220635083), 0.5);
  STF_ULP_EQUAL(erf(bs::Two<T>()), T(0.995322265018952734162069256367), 0);
  STF_ULP_EQUAL(erf(bs::Zero<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(erf(bs::Halfeps<T>()), bs::Eps<T>()*bs::rsqrt(bs::Pi<T>()), 0);
  STF_ULP_EQUAL(erf(bs::Five<T>()), T(0.99999999999846254020557196515), 0);
  STF_ULP_EQUAL(erf(T(27)), T(1), 0);

  STF_ULP_EQUAL(erf(T(-0.1)), -T(0.112462916018284892203275071744), 0);
  STF_ULP_EQUAL(erf(-bs::Half<T>()), -T(0.520499877813046537682746653892), 0.5);
  STF_ULP_EQUAL(erf(-bs::One<T>()), -T(0.842700792949714869341220635083), 0.5);
  STF_ULP_EQUAL(erf(-bs::Two<T>()), -T(0.995322265018952734162069256367), 0);
  STF_ULP_EQUAL(erf(-bs::Halfeps<T>()), -bs::Eps<T>()*bs::rsqrt(bs::Pi<T>()), 0);
  STF_ULP_EQUAL(erf(-bs::Five<T>()), -T(0.99999999999846254020557196515), 0);
  STF_ULP_EQUAL(erf(T(-27)), -T(1), 0);


}

// STF_CASE_TPL (" erf std",  STF_IEEE_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::erf;
//   using r_t = decltype(erf(T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
// #ifndef BOOST_SIMD_NO_INVALIDS
//   STF_ULP_EQUAL(erf(bs::Inf<T>(), bs::std_), bs::One<r_t>(), 0);
//   STF_ULP_EQUAL(erf(bs::Nan<T>(), bs::std_), bs::Nan<r_t>(), 0);
// #endif
//   STF_ULP_EQUAL(erf(bs::Mzero<T>(), bs::std_), bs::Zero<r_t>(), 0);
//   STF_ULP_EQUAL(erf(bs::Half<T>(), bs::std_), T(0.520499877813046537682746653892), 0);
//   STF_ULP_EQUAL(erf(bs::One<T>(), bs::std_), T(0.842700792949714869341220635083), 0);
//   STF_ULP_EQUAL(erf(bs::Two<T>(), bs::std_), T(0.995322265018952734162069256367), 0);
//   STF_ULP_EQUAL(erf(bs::Zero<T>(), bs::std_), bs::Zero<r_t>(), 0);
// }

// #include <boost/simd/arch/common/detail/generic/erf_kernel.hpp>
// STF_CASE_TPL (" pipo std",  (double))//STF_IEEE_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::detail::pipo;
//  using r_t = decltype(pipo(T()));

//   // return type conformity test
//  STF_TYPE_IS(r_t, T);

//   // specific values tests
//   STF_ULP_EQUAL(pipo(T(0.1)), erf(T(0.1), bs::std_), 0);
//   STF_ULP_EQUAL(pipo(T(0.45)), erf(T(0.45), bs::std_), 0);
//   STF_ULP_EQUAL(pipo(T(0.5)), erf(T(0.5) , bs::std_), 0.5);
//   STF_ULP_EQUAL(pipo(T(3.5)), erf(T(3.5) , bs::std_), 0.5);
//   STF_ULP_EQUAL(pipo(T(5.0)), erf(T(5.0) , bs::std_), 0.5);
//   STF_ULP_EQUAL(pipo(bs::Inf<T>()), erf(bs::Inf<T>() , bs::std_), 0);
// #ifndef BOOST_SIMD_NO_INVALIDS
//   STF_ULP_EQUAL(pipo(bs::Inf<T>()), bs::One<r_t>(), 0);
//   STF_ULP_EQUAL(pipo(bs::Nan<T>()), bs::Nan<r_t>(), 0);
// #endif
//   STF_ULP_EQUAL(pipo(bs::Mzero<T>()), bs::Zero<r_t>(), 0);
//   STF_ULP_EQUAL(pipo(bs::Half<T>()), T(0.520499877813046537682746653892), 0);
//   STF_ULP_EQUAL(pipo(bs::One<T>()), T(0.842700792949714869341220635083), 0);
//   STF_ULP_EQUAL(pipo(bs::Two<T>()), T(0.995322265018952734162069256367), 0);
//   STF_ULP_EQUAL(pipo(bs::Zero<T>()), bs::Zero<r_t>(), 0);
// }
// STF_CASE_TPL (" titi",  (float))//STF_IEEE_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::detail::titi;
// //  using r_t = decltype(pipo(T()));

//   // return type conformity test
// //  STF_TYPE_IS(r_t, T);

//   // specific values tests
//   titi<float>();
//   STF_EXPECT(true);
// }
