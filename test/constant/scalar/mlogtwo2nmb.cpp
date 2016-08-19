//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mlogtwo2nmb.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mlogtwo2nmb behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlogtwo2nmb;
  using boost::simd::Mlogtwo2nmb;
  T ref = T(0);
  STF_TYPE_IS(decltype(Mlogtwo2nmb<T>()), T);
  STF_EQUAL(Mlogtwo2nmb<T>(), ref);
  STF_EQUAL(mlogtwo2nmb( as(T{}) ),ref);
}

STF_CASE_TPL( "Check mlogtwo2nmb behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlogtwo2nmb;
  using boost::simd::Mlogtwo2nmb;
  T ref = -T(36.0436533891171560896960703158);
  STF_TYPE_IS(decltype(Mlogtwo2nmb<T>()), T);
  STF_IEEE_EQUAL(Mlogtwo2nmb<T>(), ref);
  STF_IEEE_EQUAL(mlogtwo2nmb( as(T{}) ), ref);
}

STF_CASE_TPL( "Check mlogtwo2nmb behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlogtwo2nmb;
  using boost::simd::Mlogtwo2nmb;
  T ref = -T(15.942385152878742116596);
  STF_TYPE_IS(decltype(Mlogtwo2nmb<T>()), T);
  STF_IEEE_EQUAL(Mlogtwo2nmb<T>(), ref);
  STF_IEEE_EQUAL(mlogtwo2nmb( as(T{}) ), ref);
}
