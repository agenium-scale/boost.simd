//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/powlowlim.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check powlowlim behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::powlowlim;
  using boost::simd::Powlowlim;
  T ref = T(0);
  STF_TYPE_IS(decltype(Powlowlim<T>()), T);
  STF_EQUAL(Powlowlim<T>(), ref);
  STF_EQUAL(powlowlim( as(T{}) ),ref);
}

STF_CASE_TPL( "Check powlowlim behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::powlowlim;
  using boost::simd::Powlowlim;
  T ref = T(-17183);

  STF_TYPE_IS(decltype(Powlowlim<T>()), T);
  STF_IEEE_EQUAL(Powlowlim<T>(), ref);
  STF_IEEE_EQUAL(powlowlim( as(T{}) ), ref);
}

STF_CASE_TPL( "Check powlowlim behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::powlowlim;
  using boost::simd::Powlowlim;
  T ref = T(-2400);
  STF_TYPE_IS(decltype(Powlowlim<T>()), T);
  STF_IEEE_EQUAL(Powlowlim<T>(), ref);
  STF_IEEE_EQUAL(powlowlim( as(T{}) ), ref);
}
