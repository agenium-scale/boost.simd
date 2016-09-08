//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log10_2lo.hpp>
#include <boost/simd/constant/log10_2hi.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check log10_2lo behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log10_2lo;
  using boost::simd::Log10_2lo;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log10_2lo<T>()), T);
  STF_EQUAL(Log10_2lo<T>(), ref);
  STF_EQUAL(log10_2lo( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log10_2lo behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log10_2lo;
  using boost::simd::Log10_2lo;
  T ref = T(4.6050389811952140e-6);

  STF_TYPE_IS(decltype(Log10_2lo<T>()), T);
  STF_IEEE_EQUAL(Log10_2lo<T>(), ref);
  STF_IEEE_EQUAL(log10_2lo( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log10_2lo behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log10_2lo;
  using boost::simd::Log10_2lo;
  using boost::simd::Log10_2hi;
  using boost::simd::Eps;
  using boost::simd::abs;
  double Log10_2 = 0.301029995663981195213738894724;
  STF_LESS(abs(float(double(Log10_2hi<float>())+double(Log10_2lo<float>())- Log10_2)), Eps<float>());
  T ref = T(2.4874566588550806e-4);
  STF_TYPE_IS(decltype(Log10_2lo<T>()), T);
  STF_IEEE_EQUAL(Log10_2lo<T>(), ref);
  STF_IEEE_EQUAL(log10_2lo( as(T{}) ), ref);
}
