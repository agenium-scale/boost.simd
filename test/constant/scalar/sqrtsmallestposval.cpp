//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/sqrtsmallestposval.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check sqrtsmallestposval behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::sqrtsmallestposval;
  using boost::simd::Sqrtsmallestposval;

  STF_TYPE_IS(decltype(Sqrtsmallestposval<T>()), T);
  STF_EQUAL(Sqrtsmallestposval<T>(), T(1));
  STF_EQUAL(sqrtsmallestposval( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check sqrtsmallestposval behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::sqrtsmallestposval;
  using boost::simd::Sqrtsmallestposval;
  using boost::simd::Smallestposval;

  STF_TYPE_IS(decltype(Sqrtsmallestposval<T>()), T);
  auto z1 = Sqrtsmallestposval<T>();
  STF_ULP_EQUAL(z1*z1, Smallestposval<T>(), 0.5);
  auto z2 = sqrtsmallestposval( as(T{}) );
  STF_ULP_EQUAL(z2*z2, Smallestposval<T>(), 0.5);

}
