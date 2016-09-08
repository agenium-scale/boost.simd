//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/cgold.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/five.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check cgold behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::cgold;
  using boost::simd::Cgold;

  STF_TYPE_IS(decltype(Cgold<T>()), T);
  STF_EQUAL(Cgold<T>(), T(0));
  STF_EQUAL(cgold( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check cgold behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::cgold;
  using boost::simd::Cgold;

  STF_TYPE_IS(decltype(Cgold<T>()), T);
  STF_ULP_EQUAL(Cgold<T>()+T(1), Cgold<T>()*Cgold<T>(), 1);
  STF_LESS(  Cgold<T>(), T(1));
  auto z = cgold( as(T{}));
  STF_ULP_EQUAL((z+T(1)),z*z, 1);
                                              }
