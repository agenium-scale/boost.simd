//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mlogeps2.hpp>
#include <boost/simd/constant/eps.hpp>
// #include <boost/simd/function/log.hpp>
// #include <boost/simd/function/sqr.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>
//TODO
STF_CASE_TPL( "Check mlogeps2 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlogeps2;
  using boost::simd::Mlogeps2;

  STF_TYPE_IS(decltype(Mlogeps2<T>()), T);
  STF_EQUAL(Mlogeps2<T>(), T(0));
  STF_EQUAL(mlogeps2( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check mlogeps2 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::mlogeps2;
  using boost::simd::Mlogeps2;

  STF_TYPE_IS(decltype(Mlogeps2<T>()), T);
//   STF_IEEE_EQUAL(Mlogeps2<T>(), log(sqr(Eps<T>()));
//   STF_IEEE_EQUAL(mlogeps2( as(T{}) ), log(sqr(Eps<T>()));
}
