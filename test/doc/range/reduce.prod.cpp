//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [reduceprod]
#include <boost/simd/algorithm/reduce.hpp>
#include <boost/simd/function/gamma.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <iostream>
#include <numeric>

int main()
{
  namespace bs =  boost::simd;
  float values[] = {1.f,2.f,3.f,4.f,5.f,6.f,7.f,8.f,9.f};

  std::cout << "SIMD reduce    : "
            << bs::reduce( &values[0], &values[0]+9  //range
                         , 10.0f                     //init
                         , bs::multiplies            //comutative and associative binop
                         , 1.0f                      //binop neutral element
                                  )
            << std::endl;
  std::cout << " 10!           : "
            << bs::gamma(11.0)
            << std::endl;
  return 0;
}
//! [reduceprod]
