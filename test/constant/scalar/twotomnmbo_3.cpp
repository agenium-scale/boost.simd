//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/twotomnmbo_3.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check twotomnmbo_3 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::twotomnmbo_3;
  using boost::simd::Twotomnmbo_3;
  T ref = T(0);
  STF_TYPE_IS(decltype(Twotomnmbo_3<T>()), T);
  STF_EQUAL(Twotomnmbo_3<T>(), ref);
  STF_EQUAL(twotomnmbo_3( as(T{}) ),ref);
}

STF_CASE_TPL( "Check twotomnmbo_3 behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::twotomnmbo_3;
  using boost::simd::Twotomnmbo_3;
  T ref = T( 4.806217383937348e-06);

  STF_TYPE_IS(decltype(Twotomnmbo_3<T>()), T);
  STF_IEEE_EQUAL(Twotomnmbo_3<T>(), ref);
  STF_IEEE_EQUAL(twotomnmbo_3( as(T{}) ), ref);
}

STF_CASE_TPL( "Check twotomnmbo_3 behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::twotomnmbo_3;
  using boost::simd::Twotomnmbo_3;
  T ref = T( 4.921566601151848e-03f);
  STF_TYPE_IS(decltype(Twotomnmbo_3<T>()), T);
  STF_IEEE_EQUAL(Twotomnmbo_3<T>(), ref);
  STF_IEEE_EQUAL(twotomnmbo_3( as(T{}) ), ref);
}
