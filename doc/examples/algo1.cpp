//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [transform-unary]
#include <boost/simd/algorithm/transform.hpp>
#include <boost/simd/function/minus.hpp>
#include <iostream>
#include <vector>
#include <numeric>

namespace bs = boost::simd;



int main()
{
  std::cout << std::endl;

// [init]
  std::int32_t size = 17;
  std::vector<int32_t> array(size);
  std::vector<int32_t> out(size);
  // Initialize input array
  std::iota(array.begin(), array.end(), 42);
  int32_t scalar = 42;
//! [init]

// [scalar1]
std::transform( array.data(), array.data()+size, out.data(), [scalar](std::int32_t x){return x-scalar});
//! [scalar1]

// [lambda14]
std::transform( array.data(), array.data()+size, out.data(), [scalar](const auto &x){return x-scalar});
//! [lambda14]

// [funcobj11]
struct f
{
  f(int32_t s) : s_(s),  vs_(s) { }
  int32_t operator()(int32_t a) { return a-s_; }
  bs::pack<int32_t> operator()(bs::pack<int32_t> va) { return va-vs_; }
  int32_t s_;
  bs::pack<int32_t> vs_;
};
std::transform( array.data(), array.data()+size, out.data(), f(scalar));
//! [funcobj11]
// [sqr1]
std::transform( array.data(), array.data()+size, out.data(), boost::simd::sqrt);
//! [sqr1]

  return 0;
}
//! [transform-unary]

// [squared-sum]
struct squared_sum
{
  template<typename T> T operator()(T const& a, T const& e) { return a + e*e; }
};
//! [squared-sum]

// [reduce1]
std::int32_t init = 0;
std::int32_t neutral = 0;
boost::simd::reduce( array.data(), array.data()+17
                   , init
                   , squared_sum{}, neutral
                   , boost::simd::plus
                   );

}
//! [reduce1]
