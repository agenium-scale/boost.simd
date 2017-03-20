//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [range]
#include <boost/simd/range/range.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

int main()
{
  std::vector<float> x{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

  boost::simd::pack<float> r{0};
  auto pr = boost::simd::range(x.begin(),x.end());
  for(auto&& e : pr) r += e;

  std::cout << "Sum of [" << x.front() << " ... " << x.back() << "] is " << boost::simd::sum(r) << std::endl;

  return 0;
}
//! [range]
