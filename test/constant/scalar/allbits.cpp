//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/as.hpp>
#include <limits>
#include <scalar_test.hpp>
#include <boost/simd/constant/nan.hpp>

STF_CASE_TPL( "Check allbits behavior"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::allbits;
  using boost::simd::Allbits;

  STF_TYPE_IS(decltype(Allbits<T>()), T);
  STF_EQUAL(Allbits<T>(), T(-1));
  STF_EQUAL(allbits( as(T{}) ), T(-1));
}

STF_CASE_TPL( "Check allbits behavior"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::allbits;
  using boost::simd::Allbits;

  STF_TYPE_IS(decltype(Allbits<T>()), T);
  STF_IEEE_EQUAL(Allbits<T>(), boost::simd::Nan<T>());
  STF_IEEE_EQUAL(allbits( as(T{}) ), boost::simd::Nan<T>());
}
