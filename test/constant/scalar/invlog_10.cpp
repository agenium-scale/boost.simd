//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/invlog_10.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check invlog_10 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::invlog_10;
  using boost::simd::Invlog_10;
  T ref = T(0);
  STF_TYPE_IS(decltype(Invlog_10<T>()), T);
  STF_EQUAL(Invlog_10<T>(), ref);
  STF_EQUAL(invlog_10( as(T{}) ),ref);
}


STF_CASE_TPL( "Check invlog_10 behavior for float/double"
            , (float)(double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::invlog_10;
  using boost::simd::Invlog_10;
  T ref = T(0.434294481903251827651128918917);
  STF_TYPE_IS(decltype(Invlog_10<T>()), T);
  STF_IEEE_EQUAL(Invlog_10<T>(), ref);
  STF_IEEE_EQUAL(invlog_10( as(T{}) ), ref);
}
