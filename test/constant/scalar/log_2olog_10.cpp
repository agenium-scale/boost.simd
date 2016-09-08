//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log_2olog_10.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check log_2olog_10 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log_2olog_10;
  using boost::simd::Log_2olog_10;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log_2olog_10<T>()), T);
  STF_EQUAL(Log_2olog_10<T>(), ref);
  STF_EQUAL(log_2olog_10( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log_2olog_10 behavior for double"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log_2olog_10;
  using boost::simd::Log_2olog_10;
  T ref = T(0.3010299956639811952137388947244930267681898814621085);

  STF_TYPE_IS(decltype(Log_2olog_10<T>()), T);
  STF_IEEE_EQUAL(Log_2olog_10<T>(), ref);
  STF_IEEE_EQUAL(log_2olog_10( as(T{}) ), ref);
}

