//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log10_ehi.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check log10_ehi behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log10_ehi;
  using boost::simd::Log10_ehi;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log10_ehi<T>()), T);
  STF_EQUAL(Log10_ehi<T>(), ref);
  STF_EQUAL(log10_ehi( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log10_ehi behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log10_ehi;
  using boost::simd::Log10_ehi;
  T ref = T(4.3429448190325190e-1);

  STF_TYPE_IS(decltype(Log10_ehi<T>()), T);
  STF_IEEE_EQUAL(Log10_ehi<T>(), ref);
  STF_IEEE_EQUAL(log10_ehi( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log10_ehi behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log10_ehi;
  using boost::simd::Log10_ehi;
  T ref = T(4.3359375000000000e-1);
  STF_TYPE_IS(decltype(Log10_ehi<T>()), T);
  STF_IEEE_EQUAL(Log10_ehi<T>(), ref);
  STF_IEEE_EQUAL(log10_ehi( as(T{}) ), ref);
}
