//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/bitwise_cast.hpp>
#include <simd_test.hpp>
#include <nontrivial.hpp>
#include <boost/dispatch/as.hpp>


STF_CASE( "Check bitwise_cast behavior" )
{
  namespace bs = boost::simd;
  using bs::bitwise_cast;
  STF_EXPR_IS(bitwise_cast<int32_t>(float()), int32_t);
  STF_EXPR_IS(bitwise_cast<int64_t>(double()), int64_t);
  STF_EXPR_IS(bitwise_cast<double>(int64_t()), double);
  STF_EXPR_IS(bitwise_cast<float>(int32_t()), float);
}

STF_CASE( "Check bitwise_cast behavior with float" )
{
  namespace bs = boost::simd;
  using bs::bitwise_cast;
  STF_EQUAL(bs::bitwise_cast<uint32_t>( 1.f ), 0x3F800000UL);
  STF_EQUAL(bs::bitwise_cast<float>(0x3F800000), 1.f );
}
