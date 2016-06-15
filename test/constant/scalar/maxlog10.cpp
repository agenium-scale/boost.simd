//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxlog10.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check maxlog10 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxlog10;
  using boost::simd::Maxlog10;
  T ref = T(0);
  STF_TYPE_IS(decltype(Maxlog10<T>()), T);
  STF_EQUAL(Maxlog10<T>(), ref);
  STF_EQUAL(maxlog10( as(T{}) ),ref);
}

STF_CASE_TPL( "Check maxlog10 behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxlog10;
  using boost::simd::Maxlog10;
  T ref = T(308.2547155599167);

  STF_TYPE_IS(decltype(Maxlog10<T>()), T);
  STF_IEEE_EQUAL(Maxlog10<T>(), ref);
  STF_IEEE_EQUAL(maxlog10( as(T{}) ), ref);
}

STF_CASE_TPL( "Check maxlog10 behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxlog10;
  using boost::simd::Maxlog10;
  T ref = T(38.23080825805664);
  STF_TYPE_IS(decltype(Maxlog10<T>()), T);
  STF_IEEE_EQUAL(Maxlog10<T>(), ref);
  STF_IEEE_EQUAL(maxlog10( as(T{}) ), ref);
}
