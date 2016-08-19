//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mten.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mten behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mten;
  using boost::simd::Mten;

  STF_TYPE_IS(decltype(Mten<T>()), T);
  STF_EQUAL(Mten<T>(), T(-10));
  STF_EQUAL(mten( as(T{}) ),T(-10));
}

STF_CASE_TPL( "Check mten behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mten;
  using boost::simd::Mten;

  STF_TYPE_IS(decltype(Mten<T>()), T);
  STF_IEEE_EQUAL(Mten<T>(), T(-10));
  STF_IEEE_EQUAL(mten( as(T{}) ), T(-10));
}
