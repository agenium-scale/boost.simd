//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [equalrange]
#include <boost/simd/algorithm/equal.hpp>
#include <boost/simd/function/inc.hpp>
#include <iostream>
#include <vector>

struct f
{
  template<typename T> auto operator()(T const& a, T const& b) const -> decltype(a == boost::simd::inc(b))
  {
    return (a == boost::simd::inc(b));
  }
};

int main()
{
  std::vector<float> d{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f};
  std::vector<float> e{0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f};

  bool bf = boost::simd::equal( d.data(), d.data()+7, e.data());
  bool bt = boost::simd::equal( d.data(), d.data()+7, d.data());
  bool bt1 = boost::simd::equal( d.data(), d.data()+7, e.data(), f{});

  std::cout << "bf  " << bf << '\n';
  std::cout << "bt  " << bt << '\n';
  std::cout << "bt1 " << bt1 << '\n';

  return 0;
}
//! [equalrange]
