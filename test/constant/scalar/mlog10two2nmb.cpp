//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mlog10two2nmb.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mlog10two2nmb behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlog10two2nmb;
  using boost::simd::Mlog10two2nmb;
  T ref = T(0);
  STF_TYPE_IS(decltype(Mlog10two2nmb<T>()), T);
  STF_EQUAL(Mlog10two2nmb<T>(), ref);
  STF_EQUAL(mlog10two2nmb( as(T{}) ),ref);
}

STF_CASE_TPL( "Check mlog10two2nmb behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlog10two2nmb;
  using boost::simd::Mlog10two2nmb;
  T ref = T(-15.9545897701910033463281614204);

  STF_TYPE_IS(decltype(Mlog10two2nmb<T>()), T);
  STF_IEEE_EQUAL(Mlog10two2nmb<T>(), ref);
  STF_IEEE_EQUAL(mlog10two2nmb( as(T{}) ), ref);
}

STF_CASE_TPL( "Check mlog10two2nmb behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlog10two2nmb;
  using boost::simd::Mlog10two2nmb;
  T ref = T(-6.92368990027156748991599457866);
  STF_TYPE_IS(decltype(Mlog10two2nmb<T>()), T);
  STF_IEEE_EQUAL(Mlog10two2nmb<T>(), ref);
  STF_IEEE_EQUAL(mlog10two2nmb( as(T{}) ), ref);
}
