//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/threeeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check threeeps behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::threeeps;
  using boost::simd::Threeeps;

  STF_TYPE_IS(decltype(Threeeps<T>()), T);
  STF_EQUAL(Threeeps<T>(), T(3));
  STF_EQUAL(threeeps( as(T{}) ),T(3));
}

STF_CASE_TPL( "Check threeeps behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::threeeps;
  using boost::simd::Threeeps;
  using boost::simd::Eps;

  STF_TYPE_IS(decltype(Threeeps<T>()), T);
  STF_IEEE_EQUAL(Threeeps<T>(), T(3)*Eps<T>());
  STF_IEEE_EQUAL(threeeps( as(T{}) ), T(3)*Eps<T>());
}
