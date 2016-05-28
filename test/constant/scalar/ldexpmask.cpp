//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/constant/ldexpmask.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check ldexpmask behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::ldexpmask;
  using boost::simd::Ldexpmask;

  STF_TYPE_IS(decltype(Ldexpmask<T>()), T);
  STF_EQUAL(Ldexpmask<T>(), T(0));
  STF_EQUAL(ldexpmask( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check ldexpmask behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::ldexpmask;
  using boost::simd::Ldexpmask;

  STF_TYPE_IS(decltype(Ldexpmask<T>()), boost::dispatch::as_integer_t<T>);
  STF_IEEE_EQUAL(Ldexpmask<T>(), T(0x7F800000));
  STF_IEEE_EQUAL(ldexpmask( as(T{}) ), T(0x7F800000));
}

STF_CASE_TPL( "Check ldexpmask behavior for double types"
            , (double)            )
{
  using boost::simd::as;
  using boost::simd::detail::ldexpmask;
  using boost::simd::Ldexpmask;

  STF_TYPE_IS(decltype(Ldexpmask<T>()), boost::dispatch::as_integer_t<T>);
  STF_IEEE_EQUAL(Ldexpmask<T>(), T(0x7FF0000000000000ULL));
  STF_IEEE_EQUAL(ldexpmask( as(T{}) ), T(0x7FF0000000000000ULL));
}
