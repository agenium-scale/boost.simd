//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/oneotwoeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check oneotwoeps behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::oneotwoeps;
  using boost::simd::Oneotwoeps;

  STF_TYPE_IS(decltype(Oneotwoeps<T>()), T);
  STF_EQUAL(Oneotwoeps<T>(), T(1/2.0));
  STF_EQUAL(oneotwoeps( as(T{}) ),T(1/2.0));
}

STF_CASE_TPL( "Check oneotwoeps behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::oneotwoeps;
  using boost::simd::Oneotwoeps;
  using boost::simd::Eps;

  STF_TYPE_IS(decltype(Oneotwoeps<T>()), T);
  STF_IEEE_EQUAL(Oneotwoeps<T>(), T(1/(2.0*Eps<T>())));
  STF_IEEE_EQUAL(oneotwoeps( as(T{}) ), T(1/(2.0*Eps<T>())));
}
