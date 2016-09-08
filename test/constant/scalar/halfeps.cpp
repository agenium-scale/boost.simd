//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check halfeps behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::halfeps;
  using boost::simd::Halfeps;

  STF_TYPE_IS(decltype(Halfeps<T>()), T);
  STF_EQUAL(Halfeps<T>(), T(1));
  STF_EQUAL(halfeps( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check halfeps behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::halfeps;
  using boost::simd::Halfeps;
  using boost::simd::Eps;

  STF_TYPE_IS(decltype(Halfeps<T>()), T);
  STF_IEEE_EQUAL(Halfeps<T>(), Eps<T>()/2);
  STF_IEEE_EQUAL(halfeps( as(T{}) ), Eps<T>()/2);
}
