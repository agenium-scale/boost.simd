//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/moneo_6.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check moneo_6 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::moneo_6;
  using boost::simd::Moneo_6;

  STF_TYPE_IS(decltype(Moneo_6<T>()), T);
  STF_EQUAL(Moneo_6<T>(), T(0));
  STF_EQUAL(moneo_6( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check moneo_6 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::moneo_6;
  using boost::simd::Moneo_6;

  STF_TYPE_IS(decltype(Moneo_6<T>()), T);
  STF_IEEE_EQUAL(Moneo_6<T>(), T(-1/6.0));
  STF_IEEE_EQUAL(moneo_6( as(T{}) ), T(-1/6.0));
}
