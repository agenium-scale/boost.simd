//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [all_of]
#include <boost/simd/algorithm/all_of.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <iostream>
#include <vector>

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f};

  auto rt = bs::all_of( d.data(), d.data()+7, bs::is_gtz );
  std::cout <<  "rt " << rt << "\n";
  d[4] = 0.0f;
  auto rf = bs::all_of( d.data(), d.data()+7, bs::is_gtz);
  std::cout << "rf " << rf << "\n";

  return 0;
}
//! [all_of]
