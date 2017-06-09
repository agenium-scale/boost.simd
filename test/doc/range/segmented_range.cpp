//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [segmented_range]
#include <boost/simd/range/segmented_range.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

int main()
{
  std::vector<float> x{1,2,3,4,5,6,7,8,9,10,11,12,13};

  float sr{0};
  boost::simd::pack<float> vr{0};
  auto segments = boost::simd::segmented_range(x.begin(),x.end());

  // Scalar head is empty so no iterations required

  // SIMD body
  for(boost::simd::pack<float> e : segments.body) vr += e;

  // Scalar tail
  for(float e : segments.tail) sr += e;

  std::cout << "Sum of [" << x.front() << " ... " << x.back() << "] is " << boost::simd::sum(vr) + sr << std::endl;

  return 0;
}
//! [segmented_range]
