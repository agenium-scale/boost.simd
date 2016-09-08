//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log2_em1.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check log2_em1 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log2_em1;
  using boost::simd::Log2_em1;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log2_em1<T>()), T);
  STF_EQUAL(Log2_em1<T>(), ref);
  STF_EQUAL(log2_em1( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log2_em1 behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log2_em1;
  using boost::simd::Log2_em1;
  T ref = T(0.442695040888963407359924681002);

  STF_TYPE_IS(decltype(Log2_em1<T>()), T);
  STF_IEEE_EQUAL(Log2_em1<T>(), ref);
  STF_IEEE_EQUAL(log2_em1( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log2_em1 behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log2_em1;
  using boost::simd::Log2_em1;
  T ref = T(0.4426950408889634073599246810020);
  STF_TYPE_IS(decltype(Log2_em1<T>()), T);
  STF_IEEE_EQUAL(Log2_em1<T>(), ref);
  STF_IEEE_EQUAL(log2_em1( as(T{}) ), ref);
}
