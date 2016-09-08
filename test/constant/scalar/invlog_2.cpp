//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/invlog_2.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check invlog_2 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::invlog_2;
  using boost::simd::Invlog_2;
  T ref = T(1);
  STF_TYPE_IS(decltype(Invlog_2<T>()), T);
  STF_EQUAL(Invlog_2<T>(), ref);
  STF_EQUAL(invlog_2( as(T{}) ),ref);
}

STF_CASE_TPL( "Check invlog_2 behavior for float/double"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::invlog_2;
  using boost::simd::Invlog_2;
  T ref = T(1.442695040888963407359924681);

  STF_TYPE_IS(decltype(Invlog_2<T>()), T);
  STF_IEEE_EQUAL(Invlog_2<T>(), ref);
  STF_IEEE_EQUAL(invlog_2( as(T{}) ), ref);
}

