//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [replace]
#include <boost/simd/algorithm/replace.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

namespace bs =  boost::simd;


int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{2.0f, 2.5f, 4.0f, 3.5f, 4.0f, 4.0f, 5.0f, 4.0f};
  d[7] = 42.0f;
  bs::replace( d.data(),d.data()+7, 4.0f,  0.0f);
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;

  std::vector<float> d1{4.0f, 2.5f, 4.0f, 3.5f, 4.0f, 4.0f, 5.0f, 4.0f};
  bs::replace( d1.data()+1,d1.data()+8, 4.0f,  0.0f);
  std::cout << "d1 =  (" ;
  for( auto e : d1) std::cout << e << " ";
  std::cout << ") " << std::endl;

  return 0;
 }
//! [replace]
