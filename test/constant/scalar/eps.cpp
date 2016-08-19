//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check eps behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::eps;
  using boost::simd::Eps;

  STF_TYPE_IS(decltype(Eps<T>()), T);
  STF_EQUAL(Eps<T>(), T(1));
  STF_EQUAL(eps( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check eps behavior for double type"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::eps;
  using boost::simd::Eps;

  STF_TYPE_IS(decltype(Eps<T>()), T);
  STF_IEEE_EQUAL(Eps<T>(), 2.220446049250313e-16);
  STF_IEEE_EQUAL(eps( as(T{}) ), 2.220446049250313e-16);
}
STF_CASE_TPL( "Check eps behavior for float type"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::eps;
  using boost::simd::Eps;

  STF_TYPE_IS(decltype(Eps<T>()), T);
  STF_IEEE_EQUAL(Eps<T>(),   T(1.192092895507843e-07));
  STF_IEEE_EQUAL(eps( as(T{}) ),   T(1.192092895507813e-07));
}
