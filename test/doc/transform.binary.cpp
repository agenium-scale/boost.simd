//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [transform-binary]
#include <boost/simd/algorithm/transform.hpp>
#include <iostream>
#include <vector>

struct f
{
  template<typename T> T operator()(T const& a, T const& b) const { return b/a; }
};

int main()
{
  std::vector<float> d{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f};
  std::vector<float> e{0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f};
  std::vector<float> out(7);

  boost::simd::transform( d.data(), d.data()+7, e.data(), out.data(), f{});

  for(auto x : out )
    std::cout << x << " ";

  return 0;
}
//! [transform-binary]
