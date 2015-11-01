//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log_2hi.hpp>
#include <boost/simd/constant/log_2lo.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check log_2hi behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log_2hi;
  using boost::simd::Log_2hi;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log_2hi<T>()), T);
  STF_EQUAL(Log_2hi<T>(), ref);
  STF_EQUAL(log_2hi( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log_2hi behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log_2hi;
  using boost::simd::Log_2hi;
  T ref = T(0.6931471803691238);
  #ifdef HAS_LONG_DOUBLE
  using boost::simd::Log_2lo;
  using boost::simd::Eps;
  long double L_2 = 0.693147180559945309417232121458;
  STF_LESS((double)((long double)(Log_2lo<double>())+(long double)(Log_2hi<double>()))- L_2, Eps<double>()/2);
  #endif

  STF_TYPE_IS(decltype(Log_2hi<T>()), T);
  STF_IEEE_EQUAL(Log_2hi<T>(), ref);
  STF_IEEE_EQUAL(log_2hi( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log_2hi behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log_2hi;
  using boost::simd::Log_2hi;
  using boost::simd::Log_2lo;
  using boost::simd::Log_2;
  using boost::simd::Eps;
  STF_LESS(float(double(Log_2lo<float>())+double(Log_2hi<float>())- Log_2<double>()), Eps<float>());
  T ref = T(6.9335937500000000e-1);
  STF_TYPE_IS(decltype(Log_2hi<T>()), T);
  STF_IEEE_EQUAL(Log_2hi<T>(), ref);
  STF_IEEE_EQUAL(log_2hi( as(T{}) ), ref);
}
