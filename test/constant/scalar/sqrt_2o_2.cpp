//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check sqrt_2o_2 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::sqrt_2o_2;
  using boost::simd::Sqrt_2o_2;

  STF_TYPE_IS(decltype(Sqrt_2o_2<T>()), T);
  STF_EQUAL(Sqrt_2o_2<T>(), T(0));
  STF_EQUAL(sqrt_2o_2( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check sqrt_2o_2 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::sqrt_2o_2;
  using boost::simd::Sqrt_2o_2;
  using boost::simd::Half;

  STF_TYPE_IS(decltype(Sqrt_2o_2<T>()), T);
  auto z1 = Sqrt_2o_2<T>();
  STF_ULP_EQUAL(z1*z1, Half<T>(), 0.5);
  auto z2 = sqrt_2o_2( as(T{}) );
  STF_ULP_EQUAL(z2*z2, Half<T>(), 0.5);

}
