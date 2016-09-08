//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/thirdrooteps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check thirdrooteps behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::thirdrooteps;
  using boost::simd::Thirdrooteps;

  STF_TYPE_IS(decltype(Thirdrooteps<T>()), T);
  STF_EQUAL(Thirdrooteps<T>(), T(1));
  STF_EQUAL(thirdrooteps( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check thirdrooteps behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::thirdrooteps;
  using boost::simd::Thirdrooteps;
  using boost::simd::Eps;

  STF_TYPE_IS(decltype(Thirdrooteps<T>()), T);
  auto z1 = Thirdrooteps<T>();
  STF_ULP_EQUAL(z1*z1*z1, Eps<T>(), 0.5);
  auto z2 = thirdrooteps( as(T{}));
  STF_ULP_EQUAL(z2*z2*z2, Eps<T>(), 0.5);
}
