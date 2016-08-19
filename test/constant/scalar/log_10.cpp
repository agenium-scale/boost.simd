//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log_10.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check log_10 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log_10;
  using boost::simd::Log_10;
  T ref = T(2);
  STF_TYPE_IS(decltype(Log_10<T>()), T);
  STF_EQUAL(Log_10<T>(), ref);
  STF_EQUAL(log_10( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log_10 behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log_10;
  using boost::simd::Log_10;
  T ref = T(2.30258509299404568401799145468);

  STF_TYPE_IS(decltype(Log_10<T>()), T);
  STF_IEEE_EQUAL(Log_10<T>(), ref);
  STF_IEEE_EQUAL(log_10( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log_10 behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log_10;
  using boost::simd::Log_10;
  T ref = T(2.30258509299404568401799145468);
  STF_TYPE_IS(decltype(Log_10<T>()), T);
  STF_IEEE_EQUAL(Log_10<T>(), ref);
  STF_IEEE_EQUAL(log_10( as(T{}) ), ref);
}
