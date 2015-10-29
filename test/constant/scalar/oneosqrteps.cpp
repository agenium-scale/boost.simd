//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/oneosqrteps.hpp>
#include <boost/simd/constant/sqrteps.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check oneosqrteps behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::oneosqrteps;
  using boost::simd::Oneosqrteps;

  STF_TYPE_IS(decltype(Oneosqrteps<T>()), T);
  STF_EQUAL(Oneosqrteps<T>(), T(1));
  STF_EQUAL(oneosqrteps( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check oneosqrteps behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::oneosqrteps;
  using boost::simd::Oneosqrteps;
  using boost::simd::Sqrteps;

  STF_TYPE_IS(decltype(Oneosqrteps<T>()), T);
  STF_IEEE_EQUAL(Oneosqrteps<T>(), T(1/Sqrteps<T>()));
  STF_IEEE_EQUAL(oneosqrteps( as(T{}) ), T(1/Sqrteps<T>()));
}
