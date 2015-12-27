//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/minlog2.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check minlog2 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::minlog2;
  using boost::simd::Minlog2;
  T ref = T(0);
  STF_TYPE_IS(decltype(Minlog2<T>()), T);
  STF_EQUAL(Minlog2<T>(), ref);
  STF_EQUAL(minlog2( as(T{}) ),ref);
}

STF_CASE_TPL( "Check minlog2 behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::minlog2;
  using boost::simd::Minlog2;
  T ref = T(-1022);

  STF_TYPE_IS(decltype(Minlog2<T>()), T);
  STF_IEEE_EQUAL(Minlog2<T>(), ref);
  STF_IEEE_EQUAL(minlog2( as(T{}) ), ref);
}

STF_CASE_TPL( "Check minlog2 behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::minlog2;
  using boost::simd::Minlog2;
  T ref = T(-127);
  STF_TYPE_IS(decltype(Minlog2<T>()), T);
  STF_IEEE_EQUAL(Minlog2<T>(), ref);
  STF_IEEE_EQUAL(minlog2( as(T{}) ), ref);
}
