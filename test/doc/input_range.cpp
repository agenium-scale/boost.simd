//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [input_range]
#include <boost/simd/range/input_range.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

int main()
{
  std::vector<float> x{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

  boost::simd::pack<float> r{0};
  auto pr = boost::simd::input_range(x);
  for(auto const& e : pr) r += e;

  std::cout << "Sum of [1 ... 16] is " << boost::simd::sum(r) << std::endl;

  return 0;
}
//! [input_range]
