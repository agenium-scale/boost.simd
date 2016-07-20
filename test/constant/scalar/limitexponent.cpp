//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/limitexponent.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check limitexponent behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::limitexponent;
  using boost::simd::Limitexponent;

  STF_TYPE_IS(decltype(Limitexponent<T>()), T);
  STF_EQUAL(Limitexponent<T>(), T(0));
  STF_EQUAL(limitexponent( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check limitexponent behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::limitexponent;
  using boost::simd::Limitexponent;

  STF_TYPE_IS(decltype(Limitexponent<T>()), boost::dispatch::as_integer_t<T>);
  STF_IEEE_EQUAL(Limitexponent<T>(), 128);
  STF_IEEE_EQUAL(limitexponent( as(T{}) ), 128);
}

STF_CASE_TPL( "Check limitexponent behavior for double types"
            , (double)            )
{
  using boost::simd::as;
  using boost::simd::detail::limitexponent;
  using boost::simd::Limitexponent;

  STF_TYPE_IS(decltype(Limitexponent<T>()), boost::dispatch::as_integer_t<T>);
  STF_IEEE_EQUAL(Limitexponent<T>(), 1024);
  STF_IEEE_EQUAL(limitexponent( as(T{}) ), 1024);
}
