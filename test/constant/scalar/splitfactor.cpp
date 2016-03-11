//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/splitfactor.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check splitfactor behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::splitfactor;
  using boost::simd::Splitfactor;

  STF_TYPE_IS(decltype(Splitfactor<T>()), T);
  STF_EQUAL(Splitfactor<T>(), T(0));
  STF_EQUAL(splitfactor( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check splitfactor behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::splitfactor;
  using boost::simd::Splitfactor;

  STF_TYPE_IS(decltype(Splitfactor<T>()), T);
  STF_IEEE_EQUAL(Splitfactor<T>(), T(1 << 13));
  STF_IEEE_EQUAL(splitfactor( as(T{}) ), T(1 << 13));
}
STF_CASE_TPL( "Check splitfactor behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::splitfactor;
  using boost::simd::Splitfactor;

  STF_TYPE_IS(decltype(Splitfactor<T>()), T);
  STF_IEEE_EQUAL(Splitfactor<T>(), T(1 << 27));
  STF_IEEE_EQUAL(splitfactor( as(T{}) ), T(1 << 27));
}
