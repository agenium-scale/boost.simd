//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/bitincrement.hpp>
//#include <boost/simd/function/next.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>
//TODO
STF_CASE_TPL( "Check bitincrement behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::bitincrement;
  using boost::simd::Bitincrement;

  STF_TYPE_IS(decltype(Bitincrement<T>()), T);
  STF_EQUAL(Bitincrement<T>(), T(1));
  STF_EQUAL(bitincrement( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check bitincrement behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::bitincrement;
  using boost::simd::Bitincrement;

  STF_TYPE_IS(decltype(Bitincrement<T>()), T);
  //  STF_IEEE_EQUAL(Bitincrement<T>(), boost::simd::next(T(0)));
  // STF_IEEE_EQUAL(bitincrement( as(T{}) ), boost::simd::next(T(0)));
}
