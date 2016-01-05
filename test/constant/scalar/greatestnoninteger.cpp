//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/greatestnoninteger.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check greatestnoninteger behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::greatestnoninteger;
  using boost::simd::Greatestnoninteger;

  STF_TYPE_IS(decltype(Greatestnoninteger<T>()), T);
  STF_EQUAL(Greatestnoninteger<T>(), T(0));
  STF_EQUAL(greatestnoninteger( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check greatestnoninteger behavior for double type"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::greatestnoninteger;
  using boost::simd::Greatestnoninteger;

  STF_TYPE_IS(decltype(Greatestnoninteger<T>()), T);
  STF_IEEE_EQUAL(Greatestnoninteger<T>(), 4503599627370495.5);
  STF_IEEE_EQUAL(greatestnoninteger( as(T{}) ), 4503599627370495.5);
}
STF_CASE_TPL( "Check greatestnoninteger behavior for float type"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::greatestnoninteger;
  using boost::simd::Greatestnoninteger;

  STF_TYPE_IS(decltype(Greatestnoninteger<T>()), T);
  STF_IEEE_EQUAL(Greatestnoninteger<T>(), 8388607.5f);
  STF_IEEE_EQUAL(greatestnoninteger( as(T{}) ), 8388607.5f);
}
