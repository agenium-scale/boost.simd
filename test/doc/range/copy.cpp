//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [copy]
#include <boost/simd/algorithm/copy.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
  namespace bs =  boost::simd;
  std::vector<float> d{ 0.0f, 2.0f, 0.0f, 0.0f, -1.0f, 2.0f, 0.0f, 2.0f, -1.0f, 2.0f, 0.0f, 2.0f};

  for(std::size_t i=0; i < boost::simd::pack < float>::static_size; ++i)
 {
   std::vector<float> o(7);
   auto r1 = bs::copy( d.data()+i, d.data()+i+7, o.data() );
   std::cout << "d =  (" ;
   for( auto e : o) std::cout << e << " ";
   std::cout << ") " << std::endl;
   std::cout << "nb copied " << std::distance(o.data(), r1) << "\n";
 }
  return 0;
 }
//! [copy]
