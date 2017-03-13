//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [none_of]
#include <boost/simd/algorithm/none_of.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <iostream>
#include <vector>

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

  auto rt = bs::none_of( d.data(), d.data()+7, bs::is_gtz );
  std::cout <<  "rt " << rt << "\n";
  d[1] = 1.0f;
  auto rf = bs::none_of( d.data(), d.data()+7, bs::is_gtz);
  std::cout << "rf " << rf << "\n";

  return 0;
}
//! [none_of]
