//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [segmented_aligned_range_t]
#include <boost/simd/range/segmented_aligned_range.hpp>
#include <boost/simd/literal.hpp>
#include <iostream>
#include <vector>

int main()
{
  using namespace boost::simd::literal;

  std::vector<float> data{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

  boost::simd::segmented_aligned_range_t<float*,4> r = boost::simd::segmented_aligned_range(&data[0], &data[0]+16,4_c);

  for(float v : r.head) std::cout << v << " ";
  std::cout << "\n";

  for(boost::simd::pack<float,4> v : r.body) std::cout << v << " ";
  std::cout << "\n";

  for(float v : r.tail) std::cout << v << " ";
  std::cout << "\n";

  return 0;
}
//! [segmented_aligned_range_t]
