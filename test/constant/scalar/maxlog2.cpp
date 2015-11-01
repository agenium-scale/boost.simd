//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxlog2.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check maxlog2 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxlog2;
  using boost::simd::Maxlog2;
  T ref = T(0);
  STF_TYPE_IS(decltype(Maxlog2<T>()), T);
  STF_EQUAL(Maxlog2<T>(), ref);
  STF_EQUAL(maxlog2( as(T{}) ),ref);
}

STF_CASE_TPL( "Check maxlog2 behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxlog2;
  using boost::simd::Maxlog2;
  T ref = T(1023);

  STF_TYPE_IS(decltype(Maxlog2<T>()), T);
  STF_IEEE_EQUAL(Maxlog2<T>(), ref);
  STF_IEEE_EQUAL(maxlog2( as(T{}) ), ref);
}

STF_CASE_TPL( "Check maxlog2 behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxlog2;
  using boost::simd::Maxlog2;
  T ref = T(127);
  STF_TYPE_IS(decltype(Maxlog2<T>()), T);
  STF_IEEE_EQUAL(Maxlog2<T>(), ref);
  STF_IEEE_EQUAL(maxlog2( as(T{}) ), ref);
}
