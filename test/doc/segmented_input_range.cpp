//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [segmented_input_range]
#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

int main()
{
  std::vector<float> x{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

  float sr{0};
  boost::simd::pack<float> vr{0};
  constexpr int pack_size =   boost::simd::pack<float>::static_size;
  auto prs = boost::simd::segmented_input_range<pack_size>(x);

  // Scalar prologue
  for(auto const& e :std::get<0>(prs))   sr += e;

  // SIMD main segment
  for(auto const& e : std::get<1>(prs)) vr += e;

  // Scalar epilogue
  for(auto const& e : std::get<2>(prs)) sr += e;

  std::cout << "Sum of [1 ... 16] is " << boost::simd::sum(vr) + sr << std::endl;

  return 0;
}
//! [segmented_input_range]
