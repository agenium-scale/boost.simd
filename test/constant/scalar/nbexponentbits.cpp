//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/nbexponentbits.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check nbexponentbits behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbexponentbits;
  using boost::simd::Nbexponentbits;

  STF_TYPE_IS(decltype(Nbexponentbits<T>()), T);
  STF_EQUAL(Nbexponentbits<T>(), T(0));
  STF_EQUAL(nbexponentbits( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check nbexponentbits behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbexponentbits;
  using boost::simd::Nbexponentbits;

  STF_TYPE_IS(decltype(Nbexponentbits<T>()), std::int64_t);
  STF_IEEE_EQUAL(Nbexponentbits<T>(), 11);
  STF_IEEE_EQUAL(nbexponentbits( as(T{}) ), 11);
}
STF_CASE_TPL( "Check nbexponentbits behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbexponentbits;
  using boost::simd::Nbexponentbits;

  STF_TYPE_IS(decltype(Nbexponentbits<T>()), std::int32_t);
  STF_IEEE_EQUAL(Nbexponentbits<T>(), 8);
  STF_IEEE_EQUAL(nbexponentbits( as(T{}) ), 8);
}
