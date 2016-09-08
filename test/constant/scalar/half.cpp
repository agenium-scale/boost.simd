//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/half.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check half behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::half;
  using boost::simd::Half;

  STF_TYPE_IS(decltype(Half<T>()), T);
  STF_EQUAL(Half<T>(), T(0));
  STF_EQUAL(half( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check half behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::half;
  using boost::simd::Half;

  STF_TYPE_IS(decltype(Half<T>()), T);
  STF_IEEE_EQUAL(Half<T>(), T(1/2.0));
  STF_IEEE_EQUAL(half( as(T{}) ), T(1/2.0));
}
