//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/powlargelim.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check powlargelim behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::powlargelim;
  using boost::simd::Powlargelim;
  T ref = T(0);
  STF_TYPE_IS(decltype(Powlargelim<T>()), T);
  STF_EQUAL(Powlargelim<T>(), ref);
  STF_EQUAL(powlargelim( as(T{}) ),ref);
}

STF_CASE_TPL( "Check powlargelim behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::powlargelim;
  using boost::simd::Powlargelim;
  T ref = T(16383);

  STF_TYPE_IS(decltype(Powlargelim<T>()), T);
  STF_IEEE_EQUAL(Powlargelim<T>(), ref);
  STF_IEEE_EQUAL(powlargelim( as(T{}) ), ref);
}

STF_CASE_TPL( "Check powlargelim behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::powlargelim;
  using boost::simd::Powlargelim;
  T ref = T(2047);
  STF_TYPE_IS(decltype(Powlargelim<T>()), T);
  STF_IEEE_EQUAL(Powlargelim<T>(), ref);
  STF_IEEE_EQUAL(powlargelim( as(T{}) ), ref);
}
