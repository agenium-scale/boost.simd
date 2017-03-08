//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompnot_alling file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [not_all_of]
#include <boost/simd/algorithm/not_all_of.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <iostream>
#include <vector>

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{ 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};

  auto rt1 = bs::not_all_of( d.data(), d.data()+7, bs::is_gtz );
  std::cout <<  "rt1 " << rt1 << "\n";
  auto rf1 = bs::not_all_of( d.data(), d.data()+7, bs::is_gez);
  std::cout << "rf1 " << rf1 << "\n";
  auto rt2 = bs::not_all_of( d.data()+1, d.data()+8);
  std::cout << "rt2 " << rt2 << "\n";
  auto rf2 = bs::not_all_of( d.data()+2, d.data()+9);
  std::cout << "rf2 " << rf2 << "\n";

  return 0;
}
//! [not_all_of]
