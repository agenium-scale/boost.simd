//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mthree.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mthree behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mthree;
  using boost::simd::Mthree;

  STF_TYPE_IS(decltype(Mthree<T>()), T);
  STF_EQUAL(Mthree<T>(), T(-3));
  STF_EQUAL(mthree( as(T{}) ),T(-3));
}

STF_CASE_TPL( "Check mthree behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mthree;
  using boost::simd::Mthree;

  STF_TYPE_IS(decltype(Mthree<T>()), T);
  STF_IEEE_EQUAL(Mthree<T>(), T(-3));
  STF_IEEE_EQUAL(mthree( as(T{}) ), T(-3));
}
