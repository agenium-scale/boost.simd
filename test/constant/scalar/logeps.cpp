//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/logeps.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check logeps behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::logeps;
  using boost::simd::Logeps;

  STF_TYPE_IS(decltype(Logeps<T>()), T);
  STF_EQUAL(Logeps<T>(), T(0));
  STF_EQUAL(logeps( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check logeps behavior for double type"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::logeps;
  using boost::simd::Logeps;

  STF_TYPE_IS(decltype(Logeps<T>()), T);
  STF_IEEE_EQUAL(Logeps<T>(), -36.043653389117156089696070315825);
  STF_IEEE_EQUAL(logeps( as(T{}) ), -36.043653389117156089696070315825);
}

STF_CASE_TPL( "Check logeps behavior for float type"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::logeps;
  using boost::simd::Logeps;

  STF_TYPE_IS(decltype(Logeps<T>()), T);
  STF_IEEE_EQUAL(Logeps<T>(), -15.9423847f);
  STF_IEEE_EQUAL(logeps( as(T{}) ), -15.9423847f);
}
