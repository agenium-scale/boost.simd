//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/sqrtvalmax.hpp>
#include <boost/simd/constant/valmax.hpp>
//#include <boost/simd/constant/itrunc.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>
//TODO
// STF_CASE_TPL( "Check sqrtvalmax behavior for integral types"
//             , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
//               (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
//             )
// {
//   using boost::simd::as;
//   using boost::simd::detail::sqrtvalmax;
//   using boost::simd::Sqrtvalmax;
//   using boost::simd::Valmax;

//   STF_TYPE_IS(decltype(Sqrtvalmax<T>()), T);
//   STF_EQUAL(Sqrtvalmax<T>(), boost::simd::isqrt(Valmax<T>());
//   STF_EQUAL(sqrtvalmax( as(T{}) ),boost::simd::isqrt(Valmax<T>());
// }

STF_CASE_TPL( "Check sqrtvalmax behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::sqrtvalmax;
  using boost::simd::Sqrtvalmax;
  using boost::simd::Valmax;


  STF_TYPE_IS(decltype(Sqrtvalmax<T>()), T);
  auto z1 = Sqrtvalmax<T>();
  STF_ULP_EQUAL(z1*z1, Valmax<T>(), 1.5);
  auto z2 = sqrtvalmax( as(T{}) );
  STF_ULP_EQUAL(z2*z2, Valmax<T>(), 1.5);
}
