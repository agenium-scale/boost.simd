//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [find_if]
#include <boost/simd/algorithm/find_if.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <iostream>
#include <vector>

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{ 0.0f, 2.0f, 0.0f, 0.0f, -1.0f, 2.0f, 0.0f, 4.0f};


  auto r1 = bs::find_if( d.data(), d.data()+7, bs::is_gtz );
  std::cout << "r1 " << r1 << " *r1 " << *r1 << "\n";
  auto r2 = bs::find_if( d.data(), d.data()+7, bs::is_ltz );
  std::cout << "r2 " << r2  << " *r2 " << *r2 << "\n";
  auto r3 = bs::find_if( d.data()+1, d.data()+8, bs::is_gtz );
  std::cout << "r3 " << r3  << " *r3 " << *r3 << "\n";
  auto r4 = bs::find_if( d.data()+1, d.data()+8, bs::is_ltz );
  std::cout << "r4 " << r4  << " *r4 " << *r4 << "\n";


  return 0;
}
//! [find_if]
