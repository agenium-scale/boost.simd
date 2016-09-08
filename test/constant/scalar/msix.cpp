//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/msix.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check msix behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::msix;
  using boost::simd::Msix;

  STF_TYPE_IS(decltype(Msix<T>()), T);
  STF_EQUAL(Msix<T>(), T(-6));
  STF_EQUAL(msix( as(T{}) ),T(-6));
}

STF_CASE_TPL( "Check msix behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::msix;
  using boost::simd::Msix;

  STF_TYPE_IS(decltype(Msix<T>()), T);
  STF_IEEE_EQUAL(Msix<T>(), T(-6));
  STF_IEEE_EQUAL(msix( as(T{}) ), T(-6));
}
