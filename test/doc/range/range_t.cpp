//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [range_t]
#include <boost/simd/range/range.hpp>
#include <boost/simd/literal.hpp>
#include <iostream>

int main()
{
  using namespace boost::simd::literal;

  std::int32_t data[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

  boost::simd::range_t<std::int32_t*,8> r = boost::simd::range(&data[0], &data[0]+16, 8_c);

  std::cout << *r.begin() << "\n";
  std::cout << *(r.begin()+1) << "\n";

  return 0;
}
//! [range_t]
