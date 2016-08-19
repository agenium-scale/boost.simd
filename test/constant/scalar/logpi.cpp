//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/logpi.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check logpi behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::logpi;
  using boost::simd::Logpi;

  STF_TYPE_IS(decltype(Logpi<T>()), T);
  STF_EQUAL(Logpi<T>(), T(1));
  STF_EQUAL(logpi( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check logpi behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::logpi;
  using boost::simd::Logpi;

  STF_TYPE_IS(decltype(Logpi<T>()), T);
  STF_IEEE_EQUAL(Logpi<T>(), T(1.1447298858494001741434273513531));
  STF_IEEE_EQUAL(logpi( as(T{}) ), T(1.1447298858494001741434273513531));
}
