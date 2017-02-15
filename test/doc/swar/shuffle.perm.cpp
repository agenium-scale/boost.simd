//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [shuffle.perm]
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <iostream>

struct last_
{
  template<typename I, typename C> struct apply : nsm::type_traits::integral_constant<int, C::value-1> {};
};

constexpr int reverse(int i, int c)
{
  return c - 1 - i;
}

int main()
{
  boost::simd::pack<float,4> x{1.f,2.f,3.f,4.f};

  std::cout << "Original: " << x <<  std::endl
            << "Permuted: " << boost::simd::shuffle<boost::simd::pattern<reverse>>(x) << std::endl
            << "Permuted: " << boost::simd::shuffle<last_>(x) << std::endl;

  return 0;
}
//! [shuffle.perm]
