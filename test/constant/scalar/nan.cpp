//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/as.hpp>
#include <limits>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check nan behavior with floating types", (double)(float) )
{
  using boost::simd::as;
  using boost::simd::detail::nan;
  using boost::simd::Nan;

  STF_IEEE_EQUAL(Nan<T>(), std::numeric_limits<T>::quiet_NaN());
  STF_IEEE_EQUAL(nan( as(T{}) ), std::numeric_limits<T>::quiet_NaN());
}

STF_CASE_TPL( "Check nan behavior with integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nan;
  using boost::simd::Nan;

  STF_IEEE_EQUAL(Nan<T>()       , T{0});
  STF_IEEE_EQUAL(nan( as(T{}) ) , T{0});
}
