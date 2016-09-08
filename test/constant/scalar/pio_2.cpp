//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check pio_2 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::pio_2;
  using boost::simd::Pio_2;

  STF_TYPE_IS(decltype(Pio_2<T>()), T);
  STF_EQUAL(Pio_2<T>(), T(2));
  STF_EQUAL(pio_2( as(T{}) ),T(2));
}

STF_CASE_TPL( "Check pio_2 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::pio_2;
  using boost::simd::Pio_2;

  STF_TYPE_IS(decltype(Pio_2<T>()), T);
  STF_IEEE_EQUAL(Pio_2<T>(), T(1.57079632679489661923132169164));
  STF_IEEE_EQUAL(pio_2( as(T{}) ), T(1.57079632679489661923132169164));
}
