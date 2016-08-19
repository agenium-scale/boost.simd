//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/oneosqrt5.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check oneosqrt5 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::oneosqrt5;
  using boost::simd::Oneosqrt5;

  STF_TYPE_IS(decltype(Oneosqrt5<T>()), T);
  STF_EQUAL(Oneosqrt5<T>(), T(0));
  STF_EQUAL(oneosqrt5( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check oneosqrt5 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::oneosqrt5;
  using boost::simd::Oneosqrt5;

  STF_TYPE_IS(decltype(Oneosqrt5<T>()), T);
  auto z1 = Oneosqrt5<T>();
  STF_ULP_EQUAL(z1*z1, T(1/5.0), 0.5);
  auto z2 = oneosqrt5( as(T{}) );
  STF_ULP_EQUAL(z2*z2, T(1/5.0), 0.5);
}
