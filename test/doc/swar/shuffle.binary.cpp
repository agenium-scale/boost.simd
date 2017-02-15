//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [shuffle.binary]
#include <boost/simd/pack.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <iostream>

int main()
{
  boost::simd::pack<float,4> x{1.f,2.f,3.f,4.f}, y{10.f,20.f,30.f,40.f};

  std::cout << "Original: " << x << " " << y << std::endl
            << "Permuted: " << boost::simd::shuffle<-1,3,7,-1>(x,y) << std::endl;

  return 0;
}
//! [shuffle.binary]
