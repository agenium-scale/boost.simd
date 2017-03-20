//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [segmented_range_card]
#include <boost/simd/range/segmented_range.hpp>
#include <boost/simd/literal.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

using namespace boost::simd::literal;

int main()
{
  std::vector<float> x{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

  auto segments = boost::simd::segmented_range(x, 8_c);

  // Scalar head
  for(auto&& e : segments.head) std::cout << e << " ";

  // SIMD body
  for(auto&& e : segments.body) std::cout << e << " ";

  // Scalar tail
  for(auto&& e : segments.tail) std::cout << e << " ";

  return 0;
}
//! [segmented_range_card]
