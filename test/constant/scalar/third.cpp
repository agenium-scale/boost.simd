//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/third.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check third behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::third;
  using boost::simd::Third;

  STF_TYPE_IS(decltype(Third<T>()), T);
  STF_EQUAL(Third<T>(), T(0));
  STF_EQUAL(third( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check third behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::third;
  using boost::simd::Third;

  STF_TYPE_IS(decltype(Third<T>()), T);
  STF_IEEE_EQUAL(Third<T>(), T(1/3.0));
  STF_IEEE_EQUAL(third( as(T{}) ), T(1/3.0));
}
