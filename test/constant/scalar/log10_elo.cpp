//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log10_elo.hpp>
#include <boost/simd/constant/log10_ehi.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check log10_elo behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log10_elo;
  using boost::simd::Log10_elo;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log10_elo<T>()), T);
  STF_EQUAL(Log10_elo<T>(), ref);
  STF_EQUAL(log10_elo( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log10_elo behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log10_elo;
  using boost::simd::Log10_elo;
  T ref = T(0);

  STF_TYPE_IS(decltype(Log10_elo<T>()), T);
  STF_IEEE_EQUAL(Log10_elo<T>(), ref);
  STF_IEEE_EQUAL(log10_elo( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log10_elo behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::log10_elo;
  using boost::simd::Log10_elo;
  using boost::simd::Log10_ehi;
  using boost::simd::Eps;
  using boost::simd::abs;
  double Log10_e =  (0.434294481903251827651128918917);
  STF_LESS(abs(float(double(Log10_elo<float>())+double(Log10_ehi<float>())- Log10_e)), Eps<float>());
  T ref = T(7.0073188e-04);
  STF_TYPE_IS(decltype(Log10_elo<T>()), T);
  STF_IEEE_EQUAL(Log10_elo<T>(), ref);
  STF_IEEE_EQUAL(log10_elo( as(T{}) ), ref);
}
