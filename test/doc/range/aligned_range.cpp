//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [aligned_range]
#include <boost/simd/range/aligned_range.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/literal.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

using namespace boost::simd::literal;

int main()
{
  std::vector<float, boost::simd::allocator<float>> x{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

  auto pic = boost::simd::aligned_range(x.begin(),x.end(), 8_c);
  for(auto&& e : pic) std::cout << e;
  std::cout << std::endl;

  boost::simd::pack<float> q{0};
  auto pr = boost::simd::aligned_range(x);
  for(auto&& e : pr) q += e;

  std::cout << "Sum of [" << x.front() << " ... " << x.back() << "] is " << boost::simd::sum(q) << std::endl;

  return 0;
}
//! [aligned_range]
