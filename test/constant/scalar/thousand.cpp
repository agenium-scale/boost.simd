//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/thousand.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check thousand behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::thousand;
  using boost::simd::Thousand;

  STF_TYPE_IS(decltype(Thousand<T>()), T);
  STF_EQUAL(Thousand<T>(), T(1000));
  STF_EQUAL(thousand( as(T{}) ),T(1000));
}

STF_CASE_TPL( "Check thousand behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::thousand;
  using boost::simd::Thousand;

  STF_TYPE_IS(decltype(Thousand<T>()), T);
  STF_IEEE_EQUAL(Thousand<T>(), T(1000));
  STF_IEEE_EQUAL(thousand( as(T{}) ), T(1000));
}
