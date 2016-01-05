//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log_2lo.hpp>
#include <boost/simd/constant/log_2hi.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check log_2lo behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log_2lo;
  using boost::simd::Log_2lo;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log_2lo<T>()), T);
  STF_EQUAL(Log_2lo<T>(), ref);
  STF_EQUAL(log_2lo( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log_2lo behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log_2lo;
  using boost::simd::Log_2lo;
  T ref = T(1.9082149292705877e-10);
  #ifdef HAS_LONG_DOUBLE
  using boost::simd::Log_2hi;
  using boost::simd::Eps;
  long double L_2 = 0.693147180559945309417232121458;
  STF_LESS((double)((long double)(Log_2lo<double>())+(long double)(Log_2hi<double>()))- L_2, Eps<double>()/2);
  #endif
  STF_TYPE_IS(decltype(Log_2lo<T>()), T);
  STF_IEEE_EQUAL(Log_2lo<T>(), ref);
  STF_IEEE_EQUAL(log_2lo( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log_2lo behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log_2lo;
  using boost::simd::Log_2lo;
  using boost::simd::Log_2hi;
  using boost::simd::Log_2;
  using boost::simd::Eps;
  STF_LESS(float(double(Log_2lo<float>())+double(Log_2hi<float>())- Log_2<double>()), Eps<float>());
  T ref = T(-2.1219444170128554e-4);
  STF_TYPE_IS(decltype(Log_2lo<T>()), T);
  STF_IEEE_EQUAL(Log_2lo<T>(), ref);
  STF_IEEE_EQUAL(log_2lo( as(T{}) ), ref);
}
