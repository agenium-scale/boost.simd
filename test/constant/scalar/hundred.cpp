//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/hundred.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check hundred behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::hundred;
  using boost::simd::Hundred;

  STF_TYPE_IS(decltype(Hundred<T>()), T);
  STF_EQUAL(Hundred<T>(), T(100));
  STF_EQUAL(hundred( as(T{}) ),T(100));
}

STF_CASE_TPL( "Check hundred behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::hundred;
  using boost::simd::Hundred;

  STF_TYPE_IS(decltype(Hundred<T>()), T);
  STF_IEEE_EQUAL(Hundred<T>(), T(100));
  STF_IEEE_EQUAL(hundred( as(T{}) ), T(100));
}
