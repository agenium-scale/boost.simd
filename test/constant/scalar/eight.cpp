//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/eight.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check eight behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::eight;
  using boost::simd::Eight;

  STF_TYPE_IS(decltype(Eight<T>()), T);
  STF_EQUAL(Eight<T>(), T(8));
  STF_EQUAL(eight( as(T{}) ),T(8));
}

STF_CASE_TPL( "Check eight behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::eight;
  using boost::simd::Eight;

  STF_TYPE_IS(decltype(Eight<T>()), T);
  STF_IEEE_EQUAL(Eight<T>(), T(8));
  STF_IEEE_EQUAL(eight( as(T{}) ), T(8));
}
