//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/logsqrt2pi.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check logsqrt2pi behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::logsqrt2pi;
  using boost::simd::Logsqrt2pi;

  STF_TYPE_IS(decltype(Logsqrt2pi<T>()), T);
  STF_EQUAL(Logsqrt2pi<T>(), T(1));
  STF_EQUAL(logsqrt2pi( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check logsqrt2pi behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::logsqrt2pi;
  using boost::simd::Logsqrt2pi;

  STF_TYPE_IS(decltype(Logsqrt2pi<T>()), T);
  STF_IEEE_EQUAL(Logsqrt2pi<T>(), T(0.91893853320467274178032973640562));
  STF_IEEE_EQUAL(logsqrt2pi( as(T{}) ), T(0.91893853320467274178032973640562));
}
