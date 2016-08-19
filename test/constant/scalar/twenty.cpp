//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/twenty.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check twenty behavior for all types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
              (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::twenty;
  using boost::simd::Twenty;

  STF_TYPE_IS(decltype(Twenty<T>()), T);
  STF_EQUAL(Twenty<T>(), T(20));
  STF_EQUAL(twenty( as(T{}) ),T(20));
}


