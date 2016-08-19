//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check mindenormal behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mindenormal;
  using boost::simd::Mindenormal;

  STF_TYPE_IS(decltype(Mindenormal<T>()), T);
  STF_EQUAL(Mindenormal<T>(), T(1));
  STF_EQUAL(mindenormal( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check mindenormal behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mindenormal;
  using boost::simd::Mindenormal;

  STF_TYPE_IS(decltype(Mindenormal<T>()), T);
  STF_IEEE_EQUAL(Mindenormal<T>(), 4.940656458412465e-324);
  STF_IEEE_EQUAL(mindenormal( as(T{}) ), 4.940656458412465e-324);
}
STF_CASE_TPL( "Check mindenormal behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mindenormal;
  using boost::simd::Mindenormal;

  STF_TYPE_IS(decltype(Mindenormal<T>()), T);
  STF_IEEE_EQUAL(Mindenormal<T>(), 1.4012985e-45f);
  STF_IEEE_EQUAL(mindenormal( as(T{}) ), 1.4012985e-45f);
}
