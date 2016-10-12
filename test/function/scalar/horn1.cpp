//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/horn1.hpp>

#include <scalar_test.hpp>

namespace bs =  boost::simd;


float g(const float & x)
{
  return bs::horn1<float,
    0x3f800000ul, //1
    0x40000000ul, //2
    0x40400000ul, //3
    0x40800000ul  //4
 >(x);
}

float g(const double & x)
{
  return bs::horn1<double,
    0x3ff0000000000000ull, //1
    0x4000000000000000ull, //2
    0x4008000000000000ull, //3
    0x4010000000000000ull  //4
 >(x);
}

STF_CASE_TPL( "Check horn1 behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;

  STF_EQUAL(g(bs::Zero<T>()), T(1.0));
  STF_EQUAL(g(bs::One<T>()),  T(11.0));
  STF_EQUAL(g(bs::Mone<T>()), T(-1.0));
}


