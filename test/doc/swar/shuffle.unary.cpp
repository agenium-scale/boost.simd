//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [shuffle.unary]
#include <boost/simd/pack.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <iostream>

int main()
{
  boost::simd::pack<float,4> x{1.f,2.f,3.f,4.f};

  std::cout << "Original: " << x << std::endl
            << "Permuted: " << boost::simd::shuffle<3,-1,2,0>(x) << std::endl;

  return 0;
}
//! [shuffle.unary]
