//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [shuffle.perm2]
#include <boost/simd/pack.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <iostream>

constexpr int mix_half(int i, int c)
{
  return i < c/2 ? c+i : i;
}

int main()
{
  boost::simd::pack<float,4> x{1.f,2.f,3.f,4.f}, y{10.f,20.f,30.f,40.f};

  std::cout << "Original: " << x <<  std::endl
            << "Permuted: " << boost::simd::shuffle<boost::simd::pattern<mix_half>>(x,y) << std::endl;

  return 0;
}
//! [shuffle.perm2]
