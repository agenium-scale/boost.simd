//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [transform-unary]
#include <boost/simd/algorithm/transform.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/minus.hpp>
#include <iostream>
#include <vector>
#include <numeric>

namespace bs = boost::simd;

struct f
{
  f(int32_t s) : s_(s),  vs_(s) { }
  int32_t operator()(int32_t a)
  {
    return a-s_;
  }
  bs::pack<int32_t> operator()(bs::pack<int32_t> va)
  {
    return va-vs_;
  }
  int32_t s_;
  bs::pack<int32_t> vs_;
};


int main()
{
  std::vector<float> d{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f};

  boost::simd::transform( d.data(), d.data()+7, d.data(), boost::simd::sqr );

  for(auto e : d )
    std::cout << e << " ";
  std::cout << std::endl;

  std::int32_t size = 17;
  std::vector<int32_t> array(size);
  std::vector<int32_t> out(size);
  // Initialize input array
  std::iota(array.begin(), array.end(), 42);
  int32_t scalar = 42;
  boost::simd::transform( array.data(), array.data()+size, out.data(), f(scalar) );

  for(auto e : array )
    std::cout << e << " ";
  std::cout << std::endl;
  for(auto e : out )
    std::cout << e << " ";
  std::cout << std::endl;

  return 0;
}
//! [transform-unary]
