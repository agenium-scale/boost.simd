//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/euler.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check euler behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::euler;
  using boost::simd::Euler;

  STF_TYPE_IS(decltype(Euler<T>()), T);
  STF_EQUAL(Euler<T>(), T(1));
  STF_EQUAL(euler( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check euler behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::euler;
  using boost::simd::Euler;
  T e = static_cast<T>(0.5772156649015328606065120900821);

  STF_TYPE_IS(decltype(Euler<T>()), T);
  STF_IEEE_EQUAL(Euler<T>(), e);
  STF_IEEE_EQUAL(euler( as(T{}) ), e);
}
