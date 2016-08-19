//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mseven.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mseven behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mseven;
  using boost::simd::Mseven;

  STF_TYPE_IS(decltype(Mseven<T>()), T);
  STF_EQUAL(Mseven<T>(), T(-7));
  STF_EQUAL(mseven( as(T{}) ),T(-7));
}

STF_CASE_TPL( "Check mseven behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mseven;
  using boost::simd::Mseven;

  STF_TYPE_IS(decltype(Mseven<T>()), T);
  STF_IEEE_EQUAL(Mseven<T>(), T(-7));
  STF_IEEE_EQUAL(mseven( as(T{}) ), T(-7));
}
