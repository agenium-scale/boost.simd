//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/exp_1.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check exp_1 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::exp_1;
  using boost::simd::Exp_1;
  T e = 3;
  STF_TYPE_IS(decltype(Exp_1<T>()), T);
  STF_EQUAL(Exp_1<T>(), e);
  STF_EQUAL(exp_1( as(T{}) ),e);
}

STF_CASE_TPL( "Check exp_1 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::exp_1;
  using boost::simd::Exp_1;
  T e = T(2.71828182845904523536028747135);

  STF_TYPE_IS(decltype(Exp_1<T>()), T);
  STF_IEEE_EQUAL(Exp_1<T>(), e);
  STF_IEEE_EQUAL(exp_1( as(T{}) ), e);
}
