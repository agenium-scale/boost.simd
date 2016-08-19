//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/nine.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check nine behavior for all types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
              (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nine;
  using boost::simd::Nine;

  STF_TYPE_IS(decltype(Nine<T>()), T);
  STF_EQUAL(Nine<T>(), T(9));
  STF_EQUAL(nine( as(T{}) ),T(9));
}

