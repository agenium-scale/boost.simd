//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/as.hpp>
#include <limits>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check valmin behavior on integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::valmin;
  using boost::simd::Valmin;

  STF_IEEE_EQUAL(Valmin<T>(), std::numeric_limits<T>::min());
}

STF_CASE_TPL( "Check behavior on floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::valmin;
  using boost::simd::Valmin;

  STF_IEEE_EQUAL(Valmin<T>(), -std::numeric_limits<T>::max());
}
