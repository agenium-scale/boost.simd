//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <scalar_test.hpp>

STF_CASE( "Check bitwise_cast return type" )
{
  namespace bs = boost::simd;
  using bs::bitwise_cast;
  STF_EXPR_IS(bitwise_cast<int32_t>(float()), int32_t);
  STF_EXPR_IS(bitwise_cast<int64_t>(double()), int64_t);
  STF_EXPR_IS(bitwise_cast<double>(int64_t()), double);
  STF_EXPR_IS(bitwise_cast<float>(int32_t()), float);
}

// Fake pseudo type for bitwise casting purpose
struct foo
{
  std::uint8_t  bytes[2];
  std::uint16_t word;
};

STF_CASE( "Check bitwise_cast behavior" )
{
  namespace bs = boost::simd;
  using bs::bitwise_cast;

  STF_EQUAL(bs::bitwise_cast<std::uint32_t>( 1.f ), 0x3F800000UL);
  STF_EQUAL(bs::bitwise_cast<float>(0x3F800000), 1.f );

  foo f = bs::bitwise_cast<foo>(0xFFFFFFFFU);
  STF_EQUAL( f.bytes[0], std::uint8_t(0xFF));
  STF_EQUAL( f.bytes[1], std::uint8_t(0xFF));
  STF_EQUAL( f.word    , std::uint16_t(0xFFFF));
}
