//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [find_if_not]
#include <boost/simd/algorithm/find_if_not.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/is_lez.hpp>
#include <iostream>
#include <vector>

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{ 0.0f, 2.0f, 0.0f, 0.0f, -1.0f, 2.0f, 0.0f};

  auto r1 = bs::find_if_not( d.data(), d.data()+7, bs::is_gez );
  std::cout << "r1 " << r1 << " *r1 " << *r1 << "\n";
  auto r2 = bs::find_if_not( d.data(), d.data()+7, bs::is_lez );
  std::cout << "r2 " << r2  << " *r2 " << *r2 << "\n";

  return 0;
}
//! [find_if_not]
