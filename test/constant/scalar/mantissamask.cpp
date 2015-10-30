//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mantissamask.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check mantissamask behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::mantissamask;
  using boost::simd::Mantissamask;

  STF_TYPE_IS(decltype(Mantissamask<T>()), T);
  STF_EQUAL(Mantissamask<T>(), T(0));
  STF_EQUAL(mantissamask( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check mantissamask behavior for double type"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::mantissamask;
  using boost::simd::Mantissamask;

  STF_TYPE_IS(decltype(Mantissamask<T>()), T);
  STF_IEEE_EQUAL(Mantissamask<T>(), -2.225073858507200889e-308);
  STF_IEEE_EQUAL(mantissamask( as(T{}) ), -2.225073858507200889e-308);
}
STF_CASE_TPL( "Check mantissamask behavior for float type"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::mantissamask;
  using boost::simd::Mantissamask;

  STF_TYPE_IS(decltype(Mantissamask<T>()), T);
  STF_IEEE_EQUAL(Mantissamask<T>(), -1.1754942106924410755e-38f);
  STF_IEEE_EQUAL(mantissamask( as(T{}) ), -1.1754942106924410755e-38f);
}
