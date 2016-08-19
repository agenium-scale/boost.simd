//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log2_e.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check log2_e behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log2_e;
  using boost::simd::Log2_e;
  T ref = T(1);
  STF_TYPE_IS(decltype(Log2_e<T>()), T);
  STF_EQUAL(Log2_e<T>(), ref);
  STF_EQUAL(log2_e( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log2_e behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log2_e;
  using boost::simd::Log2_e;
  T ref = T(1.442695040888963407359924681);

  STF_TYPE_IS(decltype(Log2_e<T>()), T);
  STF_IEEE_EQUAL(Log2_e<T>(), ref);
  STF_IEEE_EQUAL(log2_e( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log2_e behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log2_e;
  using boost::simd::Log2_e;
  T ref = T(1.442695040888963407359924681);
  STF_TYPE_IS(decltype(Log2_e<T>()), T);
  STF_IEEE_EQUAL(Log2_e<T>(), ref);
  STF_IEEE_EQUAL(log2_e( as(T{}) ), ref);
}
