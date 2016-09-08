//==================================================================================================
/*!!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mfive.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mfive behavior for all types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
              (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mfive;
  using boost::simd::Mfive;

  STF_TYPE_IS(decltype(Mfive<T>()), T);
  STF_EQUAL(Mfive<T>(), T(-5));
  STF_EQUAL(mfive( as(T{}) ),T(-5));
}

