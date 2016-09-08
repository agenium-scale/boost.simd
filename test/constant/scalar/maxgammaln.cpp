//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxgammaln.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check maxgammaln behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxgammaln;
  using boost::simd::Maxgammaln;

  STF_TYPE_IS(decltype(Maxgammaln<T>()), T);
  STF_EQUAL(Maxgammaln<T>(), T(1));
  STF_EQUAL(maxgammaln( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check maxgammaln behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxgammaln;
  using boost::simd::Maxgammaln;

  STF_TYPE_IS(decltype(Maxgammaln<T>()), T);
  STF_IEEE_EQUAL(Maxgammaln<T>(), 2.556348e305);
  STF_IEEE_EQUAL(maxgammaln( as(T{}) ), 2.556348e305);
}
STF_CASE_TPL( "Check maxgammaln behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxgammaln;
  using boost::simd::Maxgammaln;

  STF_TYPE_IS(decltype(Maxgammaln<T>()), T);
  STF_IEEE_EQUAL(Maxgammaln<T>(), 2.035093e36f);
  STF_IEEE_EQUAL(maxgammaln( as(T{}) ), 2.035093e36f);
}
