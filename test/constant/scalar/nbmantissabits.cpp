//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check nbmantissabits behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbmantissabits;
  using boost::simd::Nbmantissabits;

  STF_TYPE_IS(decltype(Nbmantissabits<T>()), T);
  STF_EQUAL(Nbmantissabits<T>(), T(0));
  STF_EQUAL(nbmantissabits( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check nbmantissabits behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbmantissabits;
  using boost::simd::Nbmantissabits;

  STF_TYPE_IS(decltype(Nbmantissabits<T>()), std::int64_t);
  STF_IEEE_EQUAL(Nbmantissabits<T>(), 52);
  STF_IEEE_EQUAL(nbmantissabits( as(T{}) ), 52);
}
STF_CASE_TPL( "Check nbmantissabits behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbmantissabits;
  using boost::simd::Nbmantissabits;

  STF_TYPE_IS(decltype(Nbmantissabits<T>()), std::int32_t);
  STF_IEEE_EQUAL(Nbmantissabits<T>(), 23);
  STF_IEEE_EQUAL(nbmantissabits( as(T{}) ), 23);
}
