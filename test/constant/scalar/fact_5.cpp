//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/fact_5.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check fact_5 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::fact_5;
  using boost::simd::Fact_5;

  STF_TYPE_IS(decltype(Fact_5<T>()), T);
  STF_EQUAL(Fact_5<T>(), T(120));
  STF_EQUAL(fact_5( as(T{}) ),T(120));
}

STF_CASE_TPL( "Check fact_5 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::fact_5;
  using boost::simd::Fact_5;

  STF_TYPE_IS(decltype(Fact_5<T>()), T);
  STF_IEEE_EQUAL(Fact_5<T>(), T(120));
  STF_IEEE_EQUAL(fact_5( as(T{}) ), T(120));
}
