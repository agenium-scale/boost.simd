//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxflint.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check maxflint behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxflint;
  using boost::simd::Maxflint;

  STF_TYPE_IS(decltype(Maxflint<T>()), T);
  STF_EQUAL(Maxflint<T>(), T(1));
  STF_EQUAL(maxflint( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check maxflint behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxflint;
  using boost::simd::Maxflint;

  STF_TYPE_IS(decltype(Maxflint<T>()), T);
  STF_IEEE_EQUAL(Maxflint<T>(), 9007199254740992.0);
  STF_IEEE_EQUAL(maxflint( as(T{}) ), 9007199254740992.0);
}
STF_CASE_TPL( "Check maxflint behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxflint;
  using boost::simd::Maxflint;

  STF_TYPE_IS(decltype(Maxflint<T>()), T);
  STF_IEEE_EQUAL(Maxflint<T>(), 16777216.0f);
  STF_IEEE_EQUAL(maxflint( as(T{}) ), 16777216.0f);
}
