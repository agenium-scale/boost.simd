//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxexponent.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check maxexponent behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxexponent;
  using boost::simd::Maxexponent;

  STF_TYPE_IS(decltype(Maxexponent<T>()), T);
  STF_EQUAL(Maxexponent<T>(), T(0));
  STF_EQUAL(maxexponent( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check maxexponent behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxexponent;
  using boost::simd::Maxexponent;

  STF_TYPE_IS(decltype(Maxexponent<T>()), int64_t);
  STF_IEEE_EQUAL(Maxexponent<T>(), 1023);
  STF_IEEE_EQUAL(maxexponent( as(T{}) ), 1023);
}
STF_CASE_TPL( "Check maxexponent behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxexponent;
  using boost::simd::Maxexponent;

  STF_TYPE_IS(decltype(Maxexponent<T>()), int32_t);
  STF_IEEE_EQUAL(Maxexponent<T>(), 127);
  STF_IEEE_EQUAL(maxexponent( as(T{}) ), 127);
}
