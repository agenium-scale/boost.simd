//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/invlog10_2.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check invlog10_2 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::invlog10_2;
  using boost::simd::Invlog10_2;
  T ref = T(0);
  STF_TYPE_IS(decltype(Invlog10_2<T>()), T);
  STF_EQUAL(Invlog10_2<T>(), ref);
  STF_EQUAL(invlog10_2( as(T{}) ),ref);
}

STF_CASE_TPL( "Check invlog10_2 behavior for double/float"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::invlog10_2;
  using boost::simd::Invlog10_2;
  T ref = T(3.32192809488736234787031942949);

  STF_TYPE_IS(decltype(Invlog10_2<T>()), T);
  STF_IEEE_EQUAL(Invlog10_2<T>(), ref);
  STF_IEEE_EQUAL(invlog10_2( as(T{}) ), ref);
}
