//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/twoofive.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check twoofive behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::twoofive;
  using boost::simd::Twoofive;

  STF_TYPE_IS(decltype(Twoofive<T>()), T);
  STF_EQUAL(Twoofive<T>(), T(0));
  STF_EQUAL(twoofive( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check twoofive behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::twoofive;
  using boost::simd::Twoofive;

  STF_TYPE_IS(decltype(Twoofive<T>()), T);
  STF_IEEE_EQUAL(Twoofive<T>(), T(2/5.0));
  STF_IEEE_EQUAL(twoofive( as(T{}) ), T(2/5.0));
}
