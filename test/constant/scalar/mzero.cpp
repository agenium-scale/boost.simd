//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mzero behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mzero;
  using boost::simd::Mzero;

  STF_TYPE_IS(decltype(Mzero<T>()), T);
  STF_EQUAL(Mzero<T>(), T(0));
  STF_EQUAL(mzero( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check mzero behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mzero;
  using boost::simd::Mzero;
  using boost::simd::Signmask;

  STF_TYPE_IS(decltype(Mzero<T>()), T);
  STF_IEEE_EQUAL(Mzero<T>(), T(0));
  STF_IEEE_EQUAL(Mzero<T>(), Signmask<T>());
  STF_IEEE_EQUAL(mzero( as(T{}) ), Signmask<T>());
}
