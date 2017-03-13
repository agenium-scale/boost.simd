//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [min_val]
#include <boost/simd/algorithm/min_val.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <iostream>
#include <vector>

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{ 0.0f, 2.0f, 0.0f, 0.0f, -1.0f, 2.0f, 0.0f};

  auto r1 = bs::min_val( d.data(), d.data()+7);
  std::cout << "r1 " << r1<< "\n";
  auto r2 = bs::min_val( d.data(), d.data()+7, bs::is_greater);
  std::cout << "r2 " << r2  << "\n";

  return 0;
}
//! [min_val]
