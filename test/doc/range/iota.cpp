//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [iota]
#include <boost/simd/algorithm/iota.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>

namespace bs =  boost::simd;


int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d(16);
  d[15] = 42.0f;
  bs::iota( d.data(),d.data()+15, 0.1f );
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;
  bs::iota( d.data(),d.data()+15, 2.0f, 0.5f );
  std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;
  return 0;
 }
//! [iota]
