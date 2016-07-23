//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/minexponent.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check minexponent behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::minexponent;
  using boost::simd::Minexponent;

  STF_TYPE_IS(decltype(Minexponent<T>()), T);
  STF_EQUAL(Minexponent<T>(), T(0));
  STF_EQUAL(minexponent( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check minexponent behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::minexponent;
  using boost::simd::Minexponent;

  STF_TYPE_IS(decltype(Minexponent<T>()), int64_t);
  STF_IEEE_EQUAL(Minexponent<T>(), -1022);
  STF_IEEE_EQUAL(minexponent( as(T{}) ), -1022);
}

STF_CASE_TPL( "Check minexponent behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::minexponent;
  using boost::simd::Minexponent;

  STF_TYPE_IS(decltype(Minexponent<T>()), int32_t);
  STF_IEEE_EQUAL(Minexponent<T>(), -126);
  STF_IEEE_EQUAL(minexponent( as(T{}) ), -126);
}
