//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/twotom10.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check twotom10 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::twotom10;
  using boost::simd::Twotom10;

  STF_TYPE_IS(decltype(Twotom10<T>()), T);
  STF_EQUAL(Twotom10<T>(), T(0));
  STF_EQUAL(twotom10( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check twotom10 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::twotom10;
  using boost::simd::Twotom10;

  STF_TYPE_IS(decltype(Twotom10<T>()), T);
  STF_IEEE_EQUAL(Twotom10<T>(), T(0.0009765625));
  STF_IEEE_EQUAL(twotom10( as(T{}) ), T(0.0009765625));
}
