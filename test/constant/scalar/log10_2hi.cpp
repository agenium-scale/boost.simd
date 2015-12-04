//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log10_2hi.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check log10_2hi behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log10_2hi;
  using boost::simd::Log10_2hi;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log10_2hi<T>()), T);
  STF_EQUAL(Log10_2hi<T>(), ref);
  STF_EQUAL(log10_2hi( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log10_2hi behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log10_2hi;
  using boost::simd::Log10_2hi;
  T ref = T(3.0102539062500000e-1);

  STF_TYPE_IS(decltype(Log10_2hi<T>()), T);
  STF_IEEE_EQUAL(Log10_2hi<T>(), ref);
  STF_IEEE_EQUAL(log10_2hi( as(T{}) ), ref);
}

STF_CASE_TPL( "Check log10_2hi behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log10_2hi;
  using boost::simd::Log10_2hi;
  T ref = T(3.0078125000000000e-1);
  STF_TYPE_IS(decltype(Log10_2hi<T>()), T);
  STF_IEEE_EQUAL(Log10_2hi<T>(), ref);
  STF_IEEE_EQUAL(log10_2hi( as(T{}) ), ref);
}
