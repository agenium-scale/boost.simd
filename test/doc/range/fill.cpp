//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [fill]
#include <boost/simd/algorithm/fill.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <iostream>
#include <vector>

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d(7);

  bs::fill( d.data(), d.data()+7,25.5f );
   std::cout << "d =  (" ;
  for( auto e : d) std::cout << e << " ";
  std::cout << ") " << std::endl;
  return 0;
}
//! [fill]
