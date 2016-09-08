//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log10_pi.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check log10_pi behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log10_pi;
  using boost::simd::Log10_pi;

  STF_TYPE_IS(decltype(Log10_pi<T>()), T);
  STF_EQUAL(Log10_pi<T>(), T(0));
  STF_EQUAL(log10_pi( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check log10_pi behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log10_pi;
  using boost::simd::Log10_pi;

  STF_TYPE_IS(decltype(Log10_pi<T>()), T);
  auto z = T(0.497149872694133854351268288291);
  STF_IEEE_EQUAL(Log10_pi<T>(), z);
  STF_IEEE_EQUAL(log10_pi( as(T{}) ), z);
}
