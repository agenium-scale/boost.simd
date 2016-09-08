//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mlog2two2nmb.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mlog2two2nmb behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlog2two2nmb;
  using boost::simd::Mlog2two2nmb;
  T ref = T(0);
  STF_TYPE_IS(decltype(Mlog2two2nmb<T>()), T);
  STF_EQUAL(Mlog2two2nmb<T>(), ref);
  STF_EQUAL(mlog2two2nmb( as(T{}) ),ref);
}

STF_CASE_TPL( "Check mlog2two2nmb behavior for double"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlog2two2nmb;
  using boost::simd::Mlog2two2nmb;
  using boost::simd::Nbmantissabits;
  T ref = -T(Nbmantissabits<T>());

  STF_TYPE_IS(decltype(Mlog2two2nmb<T>()), T);
  STF_IEEE_EQUAL(Mlog2two2nmb<T>(), ref);
  STF_IEEE_EQUAL(mlog2two2nmb( as(T{}) ), ref);
}

