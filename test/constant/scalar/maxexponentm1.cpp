//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxexponentm1.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check maxexponentm1 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxexponentm1;
  using boost::simd::Maxexponentm1;

  STF_TYPE_IS(decltype(Maxexponentm1<T>()), T);
  STF_EQUAL(Maxexponentm1<T>(), T(0));
  STF_EQUAL(maxexponentm1( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check maxexponentm1 behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxexponentm1;
  using boost::simd::Maxexponentm1;

  STF_TYPE_IS(decltype(Maxexponentm1<T>()), int64_t);
  STF_IEEE_EQUAL(Maxexponentm1<T>(), 1022);
  STF_IEEE_EQUAL(maxexponentm1( as(T{}) ), 1022);
}
STF_CASE_TPL( "Check maxexponentm1 behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxexponentm1;
  using boost::simd::Maxexponentm1;

  STF_TYPE_IS(decltype(Maxexponentm1<T>()), int32_t);
  STF_IEEE_EQUAL(Maxexponentm1<T>(), 126);
  STF_IEEE_EQUAL(maxexponentm1( as(T{}) ), 126);
}
